## build curl/libcurl on macos


### instruction from site

```
Did not use 10.6. Used the default one.

Apple iOS and macOS

On modern Apple operating systems, curl can be built to use Apple's SSL/TLS implementation, Secure Transport, instead of OpenSSL. To build with Secure Transport for SSL/TLS, use the configure option --with-darwinssl. (It is not necessary to use the option --without-ssl.) This feature requires iOS 5.0 or later, or OS X 10.5 ("Leopard") or later.

When Secure Transport is in use, the curl options --cacert and --capath and their libcurl equivalents, will be ignored, because Secure Transport uses the certificates stored in the Keychain to evaluate whether or not to trust the server. This, of course, includes the root certificates that ship with the OS. The --cert and --engine options, and their libcurl equivalents, are currently unimplemented in curl with Secure Transport.

For macOS users: In OS X 10.8 ("Mountain Lion"), Apple made a major overhaul to the Secure Transport API that, among other things, added support for the newer TLS 1.1 and 1.2 protocols. To get curl to support TLS 1.1 and 1.2, you must build curl on Mountain Lion or later, or by using the equivalent SDK. If you set the MACOSX_DEPLOYMENT_TARGET environmental variable to an earlier version of macOS prior to building curl, then curl will use the new Secure Transport API on Mountain Lion and later, and fall back on the older API when the same curl binary is executed on older cats. For example, running these commands in curl's directory in the shell will build the code such that it will run on cats as old as OS X 10.6 ("Snow Leopard") (using bash):

export MACOSX_DEPLOYMENT_TARGET="10.6"
./configure --with-darwinssl
make

```

### build instructions

```
https://curl.haxx.se/download.html

cd /Users/oketo/workspaces/curl-custom-build

https://curl.haxx.se/download/curl-7.67.0.tar.gz
wget https://curl.haxx.se/download/curl-7.67.0.tar.gz

tar -xzvf curl-7.67.0.tar.gz

https://curl.haxx.se/docs/install.html
how to install curl and libcurl

cd curl-7.67.0
./configure --with-darwinssl

configure: amending src/Makefile
configure: amending tests/unit/Makefile
configure: amending tests/server/Makefile
configure: amending tests/libtest/Makefile
configure: amending docs/examples/Makefile
configure: Configured to build curl/libcurl:

  Host setup:       x86_64-apple-darwin19.0.0
  Install prefix:   /usr/local
  Compiler:         gcc
   CFLAGS:          -Qunused-arguments -Os -mmacosx-version-min=10.8 -Werror=partial-availability
   CPPFLAGS:        
   LDFLAGS:         -framework CoreFoundation -framework Security
   LIBS:            -lidn2 -lldap -lz

  curl version:     7.67.0
  SSL:              enabled (Secure Transport)
  SSH:              no      (--with-libssh2)
  zlib:             enabled
  brotli:           no      (--with-brotli)
  GSS-API:          no      (--with-gssapi)
  TLS-SRP:          no      (--enable-tls-srp)
  resolver:         POSIX threaded
  IPv6:             enabled
  Unix sockets:     enabled
  IDN:              enabled (libidn2)
  Build libcurl:    Shared=yes, Static=yes
  Built-in manual:  enabled
  --libcurl option: enabled (--disable-libcurl-option)
  Verbose errors:   enabled (--disable-verbose)
  Code coverage:    disabled
  SSPI:             no      (--enable-sspi)
  ca cert bundle:   no
  ca cert path:     
  ca fallback:      
  LDAP:             enabled (OpenLDAP)
  LDAPS:            enabled
  RTSP:             enabled
  RTMP:             no      (--with-librtmp)
  Metalink:         no      (--with-libmetalink)
  PSL:              no      (libpsl not found)
  Alt-svc:          no      (--enable-alt-svc)
  HTTP2:            disabled (--with-nghttp2)
  HTTP3:            disabled (--with-ngtcp2, --with-quiche)
  ESNI:             no      (--enable-esni)
  Protocols:        DICT FILE FTP FTPS GOPHER HTTP HTTPS IMAP IMAPS LDAP LDAPS POP3 POP3S RTSP SMB SMBS SMTP SMTPS TELNET TFTP
  Features:         SSL IPv6 UnixSockets libz AsynchDNS IDN NTLM NTLM_WB

make

ld: warning: cannot export hidden symbol _curl_jmpenv from .libs/libcurl_la-hostip.o
/Library/Developer/CommandLineTools/usr/bin/ranlib: file: .libs/libcurl.a(libcurl_la-security.o) has no symbols
/Library/Developer/CommandLineTools/usr/bin/ranlib: file: .libs/libcurl.a(libcurl_la-krb5.o) has no symbols
/Library/Developer/CommandLineTools/usr/bin/ranlib: file: .libs/libcurl.a(libcurl_la-memdebug.o) has no symbols
/Library/Developer/CommandLineTools/usr/bin/ranlib: file: .libs/libcurl.a(libcurl_la-strtok.o) has no symbols
/Library/Developer/CommandLineTools/usr/bin/ranlib: file: .libs/libcurl.a(libcurl_la-http_negotiate.o) has no symbols
/Library/Developer/CommandLineTools/usr/bin/ranlib: file: .libs/libcurl.a(libcurl_la-inet_pton.o) has no symbols
/Library/Developer/CommandLineTools/usr/bin/ranlib: file: .libs/libcurl.a(libcurl_la-amigaos.o) has no symbols
/Library/Developer/CommandLineTools/usr/bin/ranlib: file: .libs/libcurl.a(libcurl_la-hostip4.o) has no symbols
/Library/Developer/CommandLineTools/usr/bin/ranlib: file: .libs/libcurl.a(libcurl_la-hostsyn.o) has no symbols
/Library/Developer/CommandLineTools/usr/bin/ranlib: file: .libs/libcurl.a(libcurl_la-inet_ntop.o) has no symbols

CC       curl-tool_vms.o
  CC       curl-tool_writeout.o
  CC       curl-tool_xattr.o
  CC       ../lib/curl-strtoofft.o
  CC       ../lib/curl-nonblock.o
  CC       ../lib/curl-warnless.o
  CC       ../lib/curl-curl_ctype.o
  CCLD     curl
make[1]: Nothing to be done for `all-am'.

make install

oketo@lasalles-MBP curl-7.67.0 % make install
Making install in lib
 .././install-sh -c -d '/usr/local/lib'
 /bin/sh ../libtool   --mode=install /usr/bin/install -c   libcurl.la '/usr/local/lib'
libtool: install: /usr/bin/install -c .libs/libcurl.4.dylib /usr/local/lib/libcurl.4.dylib
libtool: install: (cd /usr/local/lib && { ln -s -f libcurl.4.dylib libcurl.dylib || { rm -f libcurl.dylib && ln -s libcurl.4.dylib libcurl.dylib; }; })
libtool: install: /usr/bin/install -c .libs/libcurl.lai /usr/local/lib/libcurl.la
libtool: install: /usr/bin/install -c .libs/libcurl.a /usr/local/lib/libcurl.a
libtool: install: chmod 644 /usr/local/lib/libcurl.a
libtool: install: ranlib /usr/local/lib/libcurl.a

make[4]: Nothing to be done for `install-data-am'.
 .././install-sh -c -d '/usr/local/bin'
  /bin/sh ../libtool   --mode=install /usr/bin/install -c curl '/usr/local/bin'
libtool: install: /usr/bin/install -c .libs/curl /usr/local/bin/curl


/usr/local/bin/curl --version
curl 7.67.0 (x86_64-apple-darwin19.0.0) libcurl/7.67.0 SecureTransport zlib/1.2.11 libidn2/2.1.1
Release-Date: 2019-11-06
Protocols: dict file ftp ftps gopher http https imap imaps ldap ldaps pop3 pop3s rtsp smb smbs smtp smtps telnet tftp 
Features: AsynchDNS IDN IPv6 Largefile libz NTLM NTLM_WB SSL UnixSockets


ls -al /usr/local/lib/libcurl*
-rwxr-xr-x  1 oketo  admin  455496 Nov 30 03:57 /usr/local/lib/libcurl.4.dylib
-rw-r--r--  1 oketo  admin  674592 Nov 30 03:57 /usr/local/lib/libcurl.a
lrwxr-xr-x  1 oketo  admin      15 Nov 30 03:57 /usr/local/lib/libcurl.dylib -> libcurl.4.dylib
-rwxr-xr-x  1 oketo  admin     990 Nov 30 03:57 /usr/local/lib/libcurl.la
oketo@lasalles-MBP curl-7.67.0 % 

 ls -al /usr/local/include/curl 
total 432
drwxr-xr-x  11 oketo    admin     352 Nov 30 03:57 .
drwxrwxr-x  80 lasalle  admin    2560 Nov 30 03:57 ..
-rw-r--r--   1 oketo    admin  107389 Nov 30 03:57 curl.h
-rw-r--r--   1 oketo    admin    3039 Nov 30 03:57 curlver.h
-rw-r--r--   1 oketo    admin    3643 Nov 30 03:57 easy.h
-rw-r--r--   1 oketo    admin    2074 Nov 30 03:57 mprintf.h
-rw-r--r--   1 oketo    admin   16951 Nov 30 03:57 multi.h
-rw-r--r--   1 oketo    admin    1344 Nov 30 03:57 stdcheaders.h
-rw-r--r--   1 oketo    admin   18528 Nov 30 03:57 system.h
-rw-r--r--   1 oketo    admin   42258 Nov 30 03:57 typecheck-gcc.h
-rw-r--r--   1 oketo    admin    4491 Nov 30 03:57 urlapi.h

```


### libcurl example

```

CMAKELists.txt

add_library( curl SHARED IMPORTED )

set_target_properties( curl PROPERTIES IMPORTED_LOCATION /usr/local/lib/libcurl.dylib)

include_directories(/usr/local/include/curl)

target_link_libraries(
        # Specifies the target library.
        pointers

        # Links the target library
        bolib

        #curl library
        curl
        )


https://curl.haxx.se/libcurl/c/example.html
libcurl - small example snippets

https://curl.haxx.se/libcurl/c/simple.html
simple.c

int curl_simple(void) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://google.com");
        /* example.com is redirected, so we tell libcurl to follow redirection */
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    return 0;
}

Output:

/Users/oketo/CLionProjects/pointers/cmake-build-debug/pointers
<!doctype html><html itemscope="" itemtype="http://schema.org/WebPage" lang="en"><head><meta content="Search the world's information, including webpages, images, videos and more. Google has many special features to help you find exactly what you're looking for." name="description"><meta content="noodp" name="robots"><meta content="text/html; charset=UTF-8" http-equiv="Content-Type"><meta content="/images/branding/googleg/1x/googleg_standard_color_128dp.png" itemprop="image"><title>Google</title><script nonce="cfcUajbQ0s0mVC0vStMKXQ==">(function(){window.google={kEI:'Y0Hi


```


