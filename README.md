# mod_zstd

mod_zstd is a **Zstandard** compression module for Apache HTTPD Server.

- Based on [mod_brotli](https://raw.githubusercontent.com/apache/httpd/eac9bcb41a409a7eeae4f4d3890b063bf114aca0/modules/filters/mod_brotli.c)
- Inspired by [mod_zstd](https://github.com/foglede/mod_zstd) by @foglede

## Require

* [zstd](https://github.com/facebook/zstd)

## Releases

Windows MSVC binaries are provided in [releases](https://github.com/nono303/mod_zstd/releases), with **zstd dll** _(shared linking)_

> Available for **x64** - vs16 _(14.29)_& **vs17** _(14.44)_ - **AVX / AVX2**  or **SSE2**
  - _Check your [cpu supported instructions](https://raw.githubusercontent.com/nono303/PHP-memcache-dll/master/avx.png) with [CPU-Z](https://www.cpuid.com/softwares/cpu-z.html)_  

## Configuration

`httpd.conf`:

```apache
# Load module
LoadModule zstd_module modules/mod_zstd.so

<IfModule zstd_module>

  # Compression
  ## zstdCompressionLevel: 0-22 (default: 15)
  ## > 19 may fail on Browser
  ZstdCompressionLevel 10

  # Specifies how to change the ETag header when the response is compressed
  ## ZstdAlterETag: AddSuffix, NoChange, Remove (default: AddSuffix)
  ZstdAlterETag AddSuffix
  
  # Filter
  FilterDeclare COMPRESS_ZSTD CONTENT_SET
  ## by default, compress all Content_Type but it can be more specific.ex .
  ## FilterProvider COMPRESS_ZSTD ZSTD_COMPRESS "%{Content_Type} =~ m#^text/xml\b#"
  FilterProvider COMPRESS_ZSTD ZSTD_COMPRESS "%{Content_Type}=~ /.*/"
  FilterProtocol COMPRESS_ZSTD ZSTD_COMPRESS change=yes;byteranges=no
  ## Set to 1 for debug
  FilterTrace COMPRESS_ZSTD 0
  
  # Exclude
  ## Now we exclude by extension what will not be compressed 
  ## If you have other encoding filter, you may add 'no-brotli no-deflate'
  SetEnvIfNoCase Request_URI \.(?:gif|jpe?g|png|tar|zip|rar|gzip|gz|avi|mpeg|mpg|mov|mp3|mp4|exe|asf|ts|wmv|wma|qt|aiff|aif|aifc|mpga|mp2|ogg|tiff|m4a|aac|pdf|swf)$ no-zstd dont-vary

  # Make sure proxies don't deliver the wrong content
  ## https://stackoverflow.com/questions/970798/what-does-this-configuration-in-apache-mean
  Header append Vary User-Agent env=!dont-vary

  # Filter note
  ZstdFilterNote Input  zstd_in
  ZstdFilterNote Output zstd_out
  ZstdFilterNote Ratio  zstd_ratio

  LogFormat '"%r" %{zstd_out}n/%{zstd_in}n (%{zstd_ratio}n)' zstd
  CustomLog logs/access_log zstd
</IfModule>
```
