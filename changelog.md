# changelog


## 1.0.2 _(2025-02-28)_

*  add bininfo, changelog & benchmark
`README.md`
*  improve ap_log debug
`mod_zstd.c`
*  fix random crash on filter notes
`mod_zstd.c`


## 1.0.1 _(2025-02-27)_

*  1.0.1
`README.md`
`bininfo.csv`
`changelog.md`
`mod_zstd.h`
*  1.0.1
`README.md`
`changelog.md`
`mod_zstd.h`
*  add the apache2 License file https://github.com/nono303/mod_zstd/issues/2
`LICENSE`
*  fix log verbosity
`README.md`
`mod_zstd.c`
*  Add module signature
`mod_zstd.c`
*  Update README.md
*  add bininfo.csv
*  Update README.md


## 1.0.0 _(2025-02-27)_

*  add README.md
*  +ZSTD_DEFAULT_COMPRESSION_LEVEL in mod_zstd.h move typedef to mod_zstd.h ZSTD_EndDirective as process_chunk param
`mod_zstd.c`
`mod_zstd.h`
*  set ZSTD_c_nbWorkers from _SC_NPROCESSORS_ONLN or default value
`mod_zstd.c`
*  don't set/force ZstdWindowSize as already a variable aprt of Compression level (cf. https://github.com/facebook/zstd/blob/dev/lib/compress/clevels.h) add zstd_post_config() as hook_post_config
`mod_zstd.c`
`zstd_private.h`
*  fix format & ident
`mod_zstd.c`
*  better loop on buckets fix https://github.com/foglede/mod_zstd/issues/5 apr_bucket_read: APR_BLOCK_READ > APR_NONBLOCK_READ
`mod_zstd.c`
*  move zstd const to zstd_private.h
`mod_zstd.c`
`mod_zstd.h`
`zstd_private.h`
*  merge https://github.com/foglede/mod_zstd
`mod_zstd.c`
*  **Init**: copy & rename [mod_brotli.c](https://raw.githubusercontent.com/apache/httpd/eac9bcb41a409a7eeae4f4d3890b063bf114aca0/modules/filters/mod_brotli.c)

