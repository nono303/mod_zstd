/* Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define MOD_ZSTD_VERSION "1.0.2"

#define ZSTD_DEFAULT_COMPRESSION_LEVEL 15

typedef enum {
    ETAG_MODE_ADDSUFFIX = 0,
    ETAG_MODE_NOCHANGE = 1,
    ETAG_MODE_REMOVE = 2
} etag_mode_e;
	
typedef struct zstd_server_config_t {
    int compression_level, workers;
    etag_mode_e etag_mode;
    const char *note_ratio_name;
    const char *note_input_name;
    const char *note_output_name;
} zstd_server_config_t;

typedef struct zstd_ctx_t {
    ZSTD_CCtx *cctx;
    apr_bucket_brigade *bb;
    apr_off_t total_in;
    apr_off_t total_out;
} zstd_ctx_t;
