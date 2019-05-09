#include <stdio.h>
#include <stdint.h>
#include <openssl/evp.h>

int main(void) {
  EVP_MD_CTX *mdctx;
  unsigned char* digest;
  unsigned int digest_len;

  const EVP_MD* md = _EVP();

  if ((mdctx = EVP_MD_CTX_create()) == NULL)
    return EXIT_FAILURE;
  if ((digest = (uint8_t*) OPENSSL_malloc(EVP_MD_size(md))) == NULL)
    return EXIT_FAILURE;

  for (uint64_t i = 0;; ++i) {
    if (1 != EVP_DigestInit_ex(mdctx, md, NULL))
		  return EXIT_FAILURE;
    if (1 != EVP_DigestUpdate(mdctx, &i, sizeof(i)))
		  return EXIT_FAILURE;
    if (1 != EVP_DigestFinal_ex(mdctx, digest, &digest_len))
      return EXIT_FAILURE;

    if (1 != fwrite(digest, digest_len, 1, stdout))
      break;
  }

  return EXIT_SUCCESS;
}
