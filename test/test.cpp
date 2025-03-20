#include <iostream>
#include <cstring>
#include <openssl/aes.h>
#include <openssl/rand.h>
// AES加密函数
int aes_encrypt(const unsigned char *plaintext, int plaintext_len, const unsigned char *key, const unsigned char *iv,
                unsigned char *ciphertext)
{
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);
    int ciphertext_len = ((plaintext_len + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    unsigned char iv_copy[AES_BLOCK_SIZE];
    memcpy(iv_copy, iv, AES_BLOCK_SIZE);

    int result = AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &aes_key, iv_copy, AES_ENCRYPT);
    if (result != 1)
    {
        return -1;
    }

    return ciphertext_len;
}

// AES解密函数
int aes_decrypt(const unsigned char *ciphertext, int ciphertext_len, const unsigned char *key, const unsigned char *iv,
                unsigned char *plaintext)
{
    AES_KEY aes_key;
    AES_set_decrypt_key(key, 128, &aes_key);
    unsigned char iv_copy[AES_BLOCK_SIZE];
    memcpy(iv_copy, iv, AES_BLOCK_SIZE);

    int result = AES_cbc_encrypt(ciphertext, plaintext, ciphertext_len, &aes_key, iv_copy, AES_DECRYPT);
    if (result != 1)
    {
        return -1;
    }

    // 去除PKCS5Padding填充
    int padding_len = plaintext[plaintext_len - 1];
    if (padding_len > AES_BLOCK_SIZE)
    {
        return -1;
    }
    for (int i = 0; i < padding_len; i++)
    {
        if (plaintext[plaintext_len - 1 - i] != padding_len)
        {
            return -1;
        }
    }
    plaintext[plaintext_len - padding_len] = '\0';

    return plaintext_len - padding_len;
}

int main()
{
    // 生成随机的key和iv
    unsigned char key[AES_BLOCK_SIZE];
    unsigned char iv[AES_BLOCK_SIZE];
    RAND_bytes(key, AES_BLOCK_SIZE);
    RAND_bytes(iv, AES_BLOCK_SIZE);

    // 明文数据
    unsigned char plaintext[] = "Hello World!";
    int plaintext_len = strlen((char *)plaintext);

    // 加密数据
    unsigned char ciphertext[((plaintext_len + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE];
    int ciphertext_len = aes_encrypt(plaintext, plaintext_len, key, iv, ciphertext);
    if (ciphertext_len == -1)
    {
        std::cout << "Encryption failed." << std::endl;
        return 1;
    }
    std::cout << "Encrypted text: " << ciphertext << std::endl;

    // 解密数据
    unsigned char decryptedtext[ciphertext_len];
    int decryptedtext_len = aes_decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);
    if (decryptedtext_len == -1)
    {
        std::cout << "Decryption failed." << std::endl;
        return 1;
    }
    std::cout << "Decrypted text: " << decryptedtext << std::endl;

    return 0;
}