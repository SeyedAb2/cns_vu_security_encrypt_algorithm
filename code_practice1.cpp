#include <iostream>
#include <openssl/des.h>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <chrono>

int main() {
    // Generate random data (1 MB)
    const int data_size = 1024 * 1024;
    unsigned char* data = new unsigned char[data_size];
    RAND_bytes(data, data_size);

    // --- DES Encryption ---
    DES_cblock key_des;
    DES_cblock iv_des;
    RAND_bytes(key_des, sizeof(key_des));
    RAND_bytes(iv_des, sizeof(iv_des));

    DES_key_schedule schedule_des;
    DES_set_key_unchecked(&key_des, &schedule_des);

    unsigned char* encrypted_des = new unsigned char[data_size + 8];

    auto start_des = std::chrono::high_resolution_clock::now();
    DES_ncbc_encrypt(data, encrypted_des, data_size, &schedule_des, &iv_des, DES_ENCRYPT);
    auto end_des = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_des = end_des - start_des;

    // --- 3DES Encryption ---
    DES_cblock key1_3des, key2_3des, key3_3des;
    DES_key_schedule ks1, ks2, ks3;
    RAND_bytes(key1_3des, sizeof(key1_3des));
    RAND_bytes(key2_3des, sizeof(key2_3des));
    RAND_bytes(key3_3des, sizeof(key3_3des));
    DES_set_key_unchecked(&key1_3des, &ks1);
    DES_set_key_unchecked(&key2_3des, &ks2);
    DES_set_key_unchecked(&key3_3des, &ks3);

    unsigned char* encrypted_3des = new unsigned char[data_size + 8];

    auto start_3des = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < data_size; i += 8) {
        DES_ecb3_encrypt(
            (const_DES_cblock*)(data + i),
            (DES_cblock*)(encrypted_3des + i),
            &ks1, &ks2, &ks3,
            DES_ENCRYPT
        );
    }
    auto end_3des = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_3des = end_3des - start_3des;

    // --- AES Encryption ---
    AES_KEY aes_key;
    unsigned char aes_key_data[32];
    RAND_bytes(aes_key_data, sizeof(aes_key_data)); // 256-bit AES key
    AES_set_encrypt_key(aes_key_data, 256, &aes_key);

    unsigned char* encrypted_aes = new unsigned char[data_size];

    auto start_aes = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < data_size; i += AES_BLOCK_SIZE) {
        AES_encrypt(data + i, encrypted_aes + i, &aes_key);
    }
    auto end_aes = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_aes = end_aes - start_aes;

    // --- Print Results ---
    std::cout << "Encryption time using DES: " << elapsed_des.count() << " seconds" << std::endl;
    std::cout << "Encryption time using 3DES: " << elapsed_3des.count() << " seconds" << std::endl;
    std::cout << "Encryption time using AES-256: " << elapsed_aes.count() << " seconds" << std::endl;

    // --- Cleanup ---
    delete[] data;
    delete[] encrypted_des;
    delete[] encrypted_3des;
    delete[] encrypted_aes;

    return 0;
}
