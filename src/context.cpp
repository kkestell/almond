#include "context.hpp"

static void fatal(void *udata, const char *msg) {
    fprintf(stderr, "FATAL: %s\n", (msg ? msg : "no message"));
    fflush(stderr);
    abort();
}

namespace almond
{
    context::context()
    {
        ctx = duk_create_heap(NULL, NULL, NULL, NULL, fatal);
    }

    context::~context()
    {
        duk_destroy_heap(ctx);
    }

    void context::include(const std::string& buf)
    {
        duk_eval_string(ctx, buf.c_str());
    }

    std::unique_ptr<response> context::request(std::unique_ptr<almond::request> req)
    {
        // [request]
        duk_get_global_string(ctx, "request");

        // [request, {}]
        const auto req_obj_idx = duk_push_object(ctx);

        // [request, {}, 'get']
        duk_push_string(ctx, req->method.c_str());

        // [request, {method: 'get'}]
        duk_put_prop_string(ctx, req_obj_idx, "method");

        // [request, {method: 'get'}, "/"]
        duk_push_string(ctx, req->path.c_str());

        // [request, {method: 'get', path: '/'}]
        duk_put_prop_string(ctx, req_obj_idx, "path");

        // [request, {method: 'get', path: '/'}, {}]
        const auto res_obj_idx = duk_push_object(ctx);

        // [request, {method: 'get', path: '/'}, {}, '']
        duk_push_string(ctx, "");

        // [request, {method: 'get', path: '/'}, {body: ''}]
        duk_put_prop_string(ctx, res_obj_idx, "body");

        // [request({method: 'get', path: '/'}, {body: ''})]
        duk_call(ctx, 2);

        // [{body: 'foo', contentType: 'bar'}, 'foo']
        duk_get_prop_string(ctx, -1, "body");
        const auto& body = std::string(duk_to_string(ctx, -1));

        // [{body: 'foo', content_type: 'bar'}]
        duk_pop(ctx);

        // [{body: 'foo', contentType: 'bar'}, 'bar']
        duk_get_prop_string(ctx, -1, "contentType");
        const auto& content_type = std::string(duk_to_string(ctx, -1));

        // [{body: 'foo', contentType: 'bar'}]
        duk_pop(ctx);

        // []
        duk_pop(ctx);

        auto res = std::make_unique<response>();
        res->body = body;
        res->content_type = content_type;

        return res;
    }

    void context::expose(const std::string& name, duk_c_function func, int args)
    {
        duk_push_global_object(ctx);
        duk_push_c_function(ctx, func, args);
        duk_put_prop_string(ctx, -2, name.c_str());
    }
}
