/* ====================================================================
 * Copyright (c) 2015 - 2016 The GmSSL Project.  All rights reserved.
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

#ifndef HEADER_GMSKF_H
#define HEADER_GMSKF_H

#include "opensslconf.h"
#ifndef OPENSSL_NO_SKF

#include <stdio.h>
#include <openssl/sgd.h>
#include <openssl/skf.h>

#define SKF_NO_PADDING		0
#define SKF_PKCS5_PADDING	1

#define SKF_DEV_STATE_ABSENT	0x00000000
#define SKF_DEV_STATE_PRESENT	0x00000001
#define SKF_DEV_STATE_UNKNOW	0x00000010

#define SKF_CONTAINER_TYPE_UNDEF	0
#define SKF_CONTAINER_TYPE_RSA		1
#define SKF_CONTAINER_TYPE_ECC		2

#define SKF_ENVELOPEDKEYBLOB_VERSION	1
#define SKF_AUTHKEY_LENGTH		16
#define SKF_AUTHRAND_LENGTH		16
#define SKF_MAX_FILE_SIZE		(256*1024)
#define SKF_MAX_CERTIFICATE_SIZE	(8*1024)

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	union {
		ECCPUBLICKEYBLOB ecc;
		RSAPUBLICKEYBLOB rsa;
	} u;
} SKF_PUBLICKEYBLOB;
#define SKF_MAX_PUBLICKEYBOLB_LENGTH sizeof(SKF_PUBLICKEYBLOB)

typedef struct {
	char *name;
	unsigned char *buf;
	int offset;
	int length;
} SKF_FILE_OP_PARAMS;

ULONG DEVAPI SKF_LoadLibrary(LPSTR so_path, LPSTR vendor);
ULONG DEVAPI SKF_UnloadLibrary(void);
ULONG DEVAPI SKF_GetDevStateName(ULONG ulDevState, LPSTR *szName);
ULONG DEVAPI SKF_GetContainerTypeName(ULONG ulContainerType, LPSTR *szName);
ULONG DEVAPI SKF_GetAlgorName(ULONG ulAlgID, LPSTR *szName);
ULONG DEVAPI SKF_PrintDevInfo(DEVINFO *devInfo);
ULONG DEVAPI SKF_PrintRSAPublicKey(RSAPUBLICKEYBLOB *blob);
ULONG DEVAPI SKF_PrintRSAPrivateKey(RSAPRIVATEKEYBLOB *blob);
ULONG DEVAPI SKF_PrintECCPublicKey(ECCPUBLICKEYBLOB *blob);
ULONG DEVAPI SKF_PrintECCPrivateKey(ECCPRIVATEKEYBLOB *blob);
ULONG DEVAPI SKF_PrintECCCipher(ECCCIPHERBLOB *blob);
ULONG DEVAPI SKF_PrintECCSignature(ECCSIGNATUREBLOB *blob);
ULONG DEVAPI SKF_GetErrorString(ULONG ulError, LPSTR *szErrorStr);
ULONG DEVAPI SKF_NewECCCipher(ULONG ulCipherLen, ECCCIPHERBLOB **cipherBlob);
ULONG DEVAPI SKF_NewEnvelopedKey(ULONG ulCipherLen, ENVELOPEDKEYBLOB **envelopedKeyBlob);

/* BEGIN ERROR CODES */
/*
 * The following lines are auto generated by the script mkerr.pl. Any changes
 * made after this point may be overwritten when the script is next run.
 */

int ERR_load_SKF_strings(void);

/* Error codes for the SKF functions. */

/* Function codes. */
# define SKF_F_SKF_CANCELWAITFORDEVEVENT                  108
# define SKF_F_SKF_CHANGEDEVAUTHKEY                       109
# define SKF_F_SKF_CHANGEPIN                              110
# define SKF_F_SKF_CLEARSECURESTATE                       111
# define SKF_F_SKF_CLOSEAPPLICATION                       112
# define SKF_F_SKF_CLOSECONTAINER                         113
# define SKF_F_SKF_CLOSEHANDLE                            114
# define SKF_F_SKF_CONNECTDEV                             115
# define SKF_F_SKF_CREATEAPPLICATION                      116
# define SKF_F_SKF_CREATECONTAINER                        117
# define SKF_F_SKF_CREATEFILE                             118
# define SKF_F_SKF_DECRYPT                                119
# define SKF_F_SKF_DECRYPTFINAL                           120
# define SKF_F_SKF_DECRYPTINIT                            121
# define SKF_F_SKF_DECRYPTUPDATE                          122
# define SKF_F_SKF_DELETEAPPLICATION                      123
# define SKF_F_SKF_DELETECONTAINER                        124
# define SKF_F_SKF_DELETEFILE                             125
# define SKF_F_SKF_DEVAUTH                                126
# define SKF_F_SKF_DIGEST                                 127
# define SKF_F_SKF_DIGESTFINAL                            128
# define SKF_F_SKF_DIGESTINIT                             129
# define SKF_F_SKF_DIGESTUPDATE                           130
# define SKF_F_SKF_DISCONNECTDEV                          131
# define SKF_F_SKF_ECCDECRYPT                             184
# define SKF_F_SKF_ECCEXPORTSESSIONKEY                    132
# define SKF_F_SKF_ECCSIGNDATA                            133
# define SKF_F_SKF_ECCVERIFY                              134
# define SKF_F_SKF_ENCRYPT                                135
# define SKF_F_SKF_ENCRYPTFINAL                           136
# define SKF_F_SKF_ENCRYPTINIT                            137
# define SKF_F_SKF_ENCRYPTUPDATE                          138
# define SKF_F_SKF_ENUMAPPLICATION                        139
# define SKF_F_SKF_ENUMCONTAINER                          140
# define SKF_F_SKF_ENUMDEV                                141
# define SKF_F_SKF_ENUMFILES                              142
# define SKF_F_SKF_EXPORTCERTIFICATE                      143
# define SKF_F_SKF_EXPORTPUBLICKEY                        144
# define SKF_F_SKF_EXTECCDECRYPT                          145
# define SKF_F_SKF_EXTECCENCRYPT                          146
# define SKF_F_SKF_EXTECCSIGN                             147
# define SKF_F_SKF_EXTECCVERIFY                           148
# define SKF_F_SKF_EXTRSAPRIKEYOPERATION                  149
# define SKF_F_SKF_EXTRSAPUBKEYOPERATION                  150
# define SKF_F_SKF_GENECCKEYPAIR                          151
# define SKF_F_SKF_GENERATEAGREEMENTDATAANDKEYWITHECC     152
# define SKF_F_SKF_GENERATEAGREEMENTDATAWITHECC           153
# define SKF_F_SKF_GENERATEKEYWITHECC                     154
# define SKF_F_SKF_GENEXTRSAKEY                           155
# define SKF_F_SKF_GENRANDOM                              156
# define SKF_F_SKF_GENRSAKEYPAIR                          157
# define SKF_F_SKF_GETCONTAINERTYPE                       158
# define SKF_F_SKF_GETDEVINFO                             100
# define SKF_F_SKF_GETDEVSTATE                            159
# define SKF_F_SKF_GETFILEINFO                            160
# define SKF_F_SKF_GETPININFO                             161
# define SKF_F_SKF_IMPORTCERTIFICATE                      162
# define SKF_F_SKF_IMPORTECCKEYPAIR                       163
# define SKF_F_SKF_IMPORTECCPRIVATEKEY                    103
# define SKF_F_SKF_IMPORTRSAKEYPAIR                       164
# define SKF_F_SKF_IMPORTSESSIONKEY                       165
# define SKF_F_SKF_LOADLIBRARY                            101
# define SKF_F_SKF_LOCKDEV                                166
# define SKF_F_SKF_MAC                                    107
# define SKF_F_SKF_MACFINAL                               167
# define SKF_F_SKF_MACINIT                                168
# define SKF_F_SKF_MACUPDATE                              169
# define SKF_F_SKF_METHOD_LOAD_LIBRARY                    104
# define SKF_F_SKF_NEWECCCIPHER                           102
# define SKF_F_SKF_NEWENVELOPEDKEY                        183
# define SKF_F_SKF_OPENAPPLICATION                        170
# define SKF_F_SKF_OPENCONTAINER                          171
# define SKF_F_SKF_READFILE                               172
# define SKF_F_SKF_RSAEXPORTSESSIONKEY                    173
# define SKF_F_SKF_RSASIGNDATA                            174
# define SKF_F_SKF_RSAVERIFY                              175
# define SKF_F_SKF_SETLABEL                               176
# define SKF_F_SKF_SETSYMMKEY                             177
# define SKF_F_SKF_TRANSMIT                               178
# define SKF_F_SKF_UNBLOCKPIN                             179
# define SKF_F_SKF_UNLOCKDEV                              180
# define SKF_F_SKF_VERIFYPIN                              181
# define SKF_F_SKF_W                                      105
# define SKF_F_SKF_WAITFORDEVEVENT                        106
# define SKF_F_SKF_WRITEFILE                              182

/* Reason codes. */
# define SKF_R_APPLICATION_ALREADY_EXIST                  110
# define SKF_R_APPLICATION_NOT_EXISAT                     111
# define SKF_R_APPLICATION_NOT_EXIST                      171
# define SKF_R_BUFFER_TOO_SMALL                           112
# define SKF_R_CERTIFICATE_NOT_FOUND                      113
# define SKF_R_CSP_IMPORT_PUBLIC_KEY_ERROR                114
# define SKF_R_DECRYPT_INVALID_PADDING                    115
# define SKF_R_DEVICE_REMOVED                             116
# define SKF_R_DIGEST_ERROR                               117
# define SKF_R_DSO_LOAD_FAILURE                           105
# define SKF_R_ENVELOPE_PRVATE_KEY_FAILURE                104
# define SKF_R_EXPORT_FAILED                              118
# define SKF_R_FAILURE                                    108
# define SKF_R_FILE_ALREADY_EXIST                         119
# define SKF_R_FILE_ERROR                                 120
# define SKF_R_FILE_NOT_EXIST                             121
# define SKF_R_FUNCTION_NOT_SUPPORTED                     106
# define SKF_R_HASH_NOT_EQUAL                             122
# define SKF_R_IMPORT_ENVELOPED_ECC_PRIVATE_KEY_FAILURE   102
# define SKF_R_INVALID_APPLICATION_NAME                   123
# define SKF_R_INVALID_CONTAINER_TYPE                     103
# define SKF_R_INVALID_DIGEST_HANDLE                      124
# define SKF_R_INVALID_HANDLE                             125
# define SKF_R_INVALID_INPUT_LENGTH                       126
# define SKF_R_INVALID_INPUT_VALUE                        127
# define SKF_R_INVALID_KEY_INFO_TYPE                      128
# define SKF_R_INVALID_KEY_USAGE                          129
# define SKF_R_INVALID_MAC_LENGTH                         130
# define SKF_R_INVALID_MODULUS_LENGTH                     131
# define SKF_R_INVALID_NAME_LENGTH                        132
# define SKF_R_INVALID_OBJECT                             133
# define SKF_R_INVALID_PARAMETER                          134
# define SKF_R_INVALID_PIN                                135
# define SKF_R_INVALID_PIN_LENGTH                         136
# define SKF_R_INVALID_RSA_MODULUS_LENGTH                 137
# define SKF_R_INVALID_USER_TYPE                          138
# define SKF_R_KEY_NOT_FOUND                              139
# define SKF_R_LOAD_LIBRARY_FAILURE                       101
# define SKF_R_MEMORY_ERROR                               140
# define SKF_R_NOT_INITIALIZED                            141
# define SKF_R_NOT_SUPPORTED_CIPHER_ALGOR                 168
# define SKF_R_NOT_SUPPORTED_DIGEST_ALGOR                 169
# define SKF_R_NOT_SUPPORTED_PKEY_ALGOR                   170
# define SKF_R_NO_EVENT                                   142
# define SKF_R_NO_SPACE                                   143
# define SKF_R_NULL_ARGUMENT                              100
# define SKF_R_OPERATION_NOT_SUPPORTED                    144
# define SKF_R_PIN_INCORRECT                              145
# define SKF_R_PIN_LOCKED                                 146
# define SKF_R_RANDOM_GENERATION_FAILED                   147
# define SKF_R_READ_FILE_FAILURE                          148
# define SKF_R_RSA_DECRYPTION_FAILURE                     149
# define SKF_R_RSA_ENCRYPTION_FAILURE                     150
# define SKF_R_RSA_KEY_GENERATION_FAILURE                 151
# define SKF_R_SKF_METHOD_NOT_INITIALIZED                 107
# define SKF_R_SUCCESS                                    152
# define SKF_R_TIMEOUT                                    153
# define SKF_R_UNKNOWN_ERROR                              109
# define SKF_R_UNKNOWN_VENDOR                             158
# define SKF_R_USER_ALREADY_LOGGED_IN                     154
# define SKF_R_USER_NOT_LOGGED_IN                         155
# define SKF_R_USER_PIN_NOT_INITIALIZED                   156
# define SKF_R_WISEC_AUTH_BLOCKED                         159
# define SKF_R_WISEC_CERTNOUSAGEERR                       160
# define SKF_R_WISEC_CERTUSAGEERR                         161
# define SKF_R_WISEC_CONTAINER_EXISTS                     162
# define SKF_R_WISEC_CONTAINER_NOT_EXISTS                 163
# define SKF_R_WISEC_DEVNOAUTH                            164
# define SKF_R_WISEC_FILEATTRIBUTEERR                     165
# define SKF_R_WISEC_INVALIDCONTAINERERR                  166
# define SKF_R_WISEC_KEYNOUSAGEERR                        167
# define SKF_R_WRITE_FILE_FAILURE                         157

# ifdef  __cplusplus
}
# endif
#endif
#endif
