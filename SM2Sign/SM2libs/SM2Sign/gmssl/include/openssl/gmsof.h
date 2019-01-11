/* ====================================================================
 * Copyright (c) 2016 The GmSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the GmSSL Project.
 *    (http://gmssl.org/)"
 *
 * 4. The name "GmSSL Project" must not be used to endorse or promote
 *    products derived from this software without prior written
 *    permission. For written permission, please contact
 *    guanzhi1980@gmail.com.
 *
 * 5. Products derived from this software may not be called "GmSSL"
 *    nor may "GmSSL" appear in their names without prior written
 *    permission of the GmSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the GmSSL Project
 *    (http://gmssl.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE GmSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE GmSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 */

#ifndef HEADER_GMSOF_H
#define HEADER_GMSOF_H

#include "opensslconf.h"
#ifndef OPENSSL_NO_SOF

#include <stdio.h>
#include <openssl/sgd.h>
#include <openssl/sof.h>

/* SOF_SignMessage Flag */
#define SOF_FLAG_SIG_WITH_MESSAGE	0
#define SOF_FLAG_SIG_WITHOUT_MESSAGE	1

/* SOF_GetInfoFromSignedMessage Type */
#define SOF_SIGNED_MESSAGE_MESSAGE	1
#define SOF_SIGNED_MESSAGE_CERT		2
#define SOF_SIGNED_MESSAGE_SIGNATURE	3

/* SOF_GetXMLSignatureInfo */
#define SOF_XML_TYPE_MESSAGE		1
#define SOF_XML_TYPE_DIGEST		2
#define SOF_XML_TYPE_SIGNATURE		3
#define SOF_XML_TYPE_CERTIFICATE	4
#define SOF_XML_TYPE_DIGEST_ALGOR	5
#define SOF_XML_TYPE_SIGN_ALGOR		6



#ifdef __cplusplus
extern "C" {
#endif

const char *SOF_GetErrorString(int err);

/* BEGIN ERROR CODES */
/*
 * The following lines are auto generated by the script mkerr.pl. Any changes
 * made after this point may be overwritten when the script is next run.
 */

int ERR_load_SOF_strings(void);

/* Error codes for the SOF functions. */

/* Function codes. */
# define SOF_F_SOF_CHANGEPASSWD                           100
# define SOF_F_SOF_CREATETIMESTAMPREQUEST                 101
# define SOF_F_SOF_CREATETIMESTAMPRESPONSE                102
# define SOF_F_SOF_DECRYPTDATA                            103
# define SOF_F_SOF_DECRYPTFILE                            104
# define SOF_F_SOF_DELCERTTRUSTLIST                       105
# define SOF_F_SOF_ENCRYPTDATA                            106
# define SOF_F_SOF_ENCRYPTFILE                            107
# define SOF_F_SOF_EXPORTEXCHANGEUSERCERT                 108
# define SOF_F_SOF_EXPORTUSERCERT                         109
# define SOF_F_SOF_G                                      143
# define SOF_F_SOF_GENRANDOM                              110
# define SOF_F_SOF_GETCERTINFO                            111
# define SOF_F_SOF_GETCERTINFOBYOID                       112
# define SOF_F_SOF_GETCERTTRUSTLIST                       113
# define SOF_F_SOF_GETCERTTRUSTLISTALTNAMES               114
# define SOF_F_SOF_GETDEVICEINFO                          115
# define SOF_F_SOF_GETENCRYPTMETHOD                       116
# define SOF_F_SOF_GETINFOFROMSIGNEDMESSAGE               117
# define SOF_F_SOF_GETLASTERROR                           118
# define SOF_F_SOF_GETPINRETRYCOUNT                       119
# define SOF_F_SOF_GETSERVERCERTIFICATE                   120
# define SOF_F_SOF_GETSIGNMETHOD                          121
# define SOF_F_SOF_GETTIMESTAMPINFO                       122
# define SOF_F_SOF_GETUSERLIST                            123
# define SOF_F_SOF_GETVERSION                             124
# define SOF_F_SOF_GETXMLSIGNATUREINFO                    125
# define SOF_F_SOF_INITCERTAPPPOLICY                      126
# define SOF_F_SOF_LOGIN                                  127
# define SOF_F_SOF_SETCERTTRUSTLIST                       128
# define SOF_F_SOF_SETENCRYPTMETHOD                       129
# define SOF_F_SOF_SETSIGNMETHOD                          130
# define SOF_F_SOF_SIGNDATA                               131
# define SOF_F_SOF_SIGNDATAXML                            132
# define SOF_F_SOF_SIGNFILE                               133
# define SOF_F_SOF_SIGNMESSAGE                            134
# define SOF_F_SOF_SIGNMESSAGEDETACH                      135
# define SOF_F_SOF_VALIDATECERT                           136
# define SOF_F_SOF_VERIFYSIGNEDDATA                       137
# define SOF_F_SOF_VERIFYSIGNEDDATAXML                    138
# define SOF_F_SOF_VERIFYSIGNEDFILE                       139
# define SOF_F_SOF_VERIFYSIGNEDMESSAGE                    140
# define SOF_F_SOF_VERIFYSIGNEDMESSAGEDETACH              141
# define SOF_F_SOF_VERIFYTIMESTAMP                        142

/* Reason codes. */
# define SOF_R_DECODE_FAILURE                             101
# define SOF_R_INVALID_CERT_ATTRIBUTE                     103
# define SOF_R_NOT_IMPLEMENTED                            100
# define SOF_R_READ_FILE_FAILURE                          102

# ifdef  __cplusplus
}
# endif
#endif
#endif
