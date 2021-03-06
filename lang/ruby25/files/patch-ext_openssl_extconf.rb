--- ext/openssl/extconf.rb.orig	2018-04-02 09:57:14 UTC
+++ ext/openssl/extconf.rb
@@ -122,8 +122,11 @@ OpenSSL.check_func_or_macro("SSL_get_ser
 have_func("SSL_is_server")
 
 # added in 1.1.0
+if !have_struct_member("SSL", "ctx", "openssl/ssl.h") ||
+    try_static_assert("LIBRESSL_VERSION_NUMBER >= 0x2070000fL", "openssl/opensslv.h")
+  $defs.push("-DHAVE_OPAQUE_OPENSSL")
+end
 have_func("CRYPTO_lock") || $defs.push("-DHAVE_OPENSSL_110_THREADING_API")
-have_struct_member("SSL", "ctx", "openssl/ssl.h") || $defs.push("-DHAVE_OPAQUE_OPENSSL")
 have_func("BN_GENCB_new")
 have_func("BN_GENCB_free")
 have_func("BN_GENCB_get_arg")
