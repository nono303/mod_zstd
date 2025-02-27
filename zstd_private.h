// >> copy from zstd.h
	/* compression parameter bounds */
	#define ZSTD_WINDOWLOG_MAX_32    30
	#define ZSTD_WINDOWLOG_MAX_64    31
	#define ZSTD_WINDOWLOG_MAX     ((int)(sizeof(size_t) == 4 ? ZSTD_WINDOWLOG_MAX_32 : ZSTD_WINDOWLOG_MAX_64))
	#define ZSTD_WINDOWLOG_MIN       10
	#define ZSTD_HASHLOG_MAX       ((ZSTD_WINDOWLOG_MAX < 30) ? ZSTD_WINDOWLOG_MAX : 30)
	#define ZSTD_HASHLOG_MIN          6
	#define ZSTD_CHAINLOG_MAX_32     29
	#define ZSTD_CHAINLOG_MAX_64     30
	#define ZSTD_CHAINLOG_MAX      ((int)(sizeof(size_t) == 4 ? ZSTD_CHAINLOG_MAX_32 : ZSTD_CHAINLOG_MAX_64))
	#define ZSTD_CHAINLOG_MIN        ZSTD_HASHLOG_MIN
	#define ZSTD_SEARCHLOG_MAX      (ZSTD_WINDOWLOG_MAX-1)
	#define ZSTD_SEARCHLOG_MIN        1
	#define ZSTD_MINMATCH_MAX         7   /* only for ZSTD_fast, other strategies are limited to 6 */
	#define ZSTD_MINMATCH_MIN         3   /* only for ZSTD_btopt+, faster strategies are limited to 4 */
	#define ZSTD_TARGETLENGTH_MAX    ZSTD_BLOCKSIZE_MAX
	#define ZSTD_TARGETLENGTH_MIN     0   /* note : comparing this constant to an unsigned results in a tautological test */
	#define ZSTD_STRATEGY_MIN        ZSTD_fast
	#define ZSTD_STRATEGY_MAX        ZSTD_btultra2
	#define ZSTD_BLOCKSIZE_MAX_MIN (1 << 10) /* The minimum valid max blocksize. Maximum blocksizes smaller than this make compressBound() inaccurate. */


	#define ZSTD_OVERLAPLOG_MIN       0
	#define ZSTD_OVERLAPLOG_MAX       9

	#define ZSTD_WINDOWLOG_LIMIT_DEFAULT 27   /* by default, the streaming decoder will refuse any frame
											   * requiring larger than (1<<ZSTD_WINDOWLOG_LIMIT_DEFAULT) window size,
											   * to preserve host's memory from unreasonable requirements.
											   * This limit can be overridden using ZSTD_DCtx_setParameter(,ZSTD_d_windowLogMax,).
											   * The limit does not apply for one-pass decoders (such as ZSTD_decompress()), since no additional memory is allocated */
// >> end of copy from zstd.h
