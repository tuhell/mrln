#ifndef STR_H
#define STR_H

#include <mrln/alctr.h>
#include <mrln/type.h>

// TODO should strings be utf-8 compatible?

typedef struct str_t str_t;
struct str_t {
  alctr_t *alctr;
  u64 inplace : 1;
  u64 space : 63;
  u8 *buf;
  u64 len;
};

typedef struct str_view_t str_view_t;
struct str_view_t {
  u8 *buf;
  u64 len;
};

error_t *str_create(str_t **sp, alctr_t *a);
void str_destroy(str_t *s);

error_t *str_init(str_t *s, alctr_t *a);
error_t *str_deinit(str_t *s);

error_t *str_cat_cstr(str_t *s, const char *cstr);
error_t *str_cat_str(str_t *s, const str_t *ss);
error_t *str_cat_ch(str_t *s, const char c);
error_t *str_cat_view(str_t *s, const str_view_t v);

error_t *str_cat_replace(str_t *s, const str_view_t old, const str_view_t new,
                         i64 n);

#endif // STR_H
