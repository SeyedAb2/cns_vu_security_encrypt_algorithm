#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <time.h>

#define BUFFER_SIZE 4096

void calculate_md5(const char* filename) {
    unsigned char buffer[BUFFER_SIZE];
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5_CTX ctx;
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Cannot open file for MD5");
        return;
    }

    MD5_Init(&ctx);
    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, file)) != 0) {
        MD5_Update(&ctx, buffer, bytes);
    }
    MD5_Final(digest, &ctx);
    fclose(file);

    printf("MD5: ");
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
        printf("%02x", digest[i]);
    printf("\n");
}

void calculate_sha1(const char* filename) {
    unsigned char buffer[BUFFER_SIZE];
    unsigned char digest[SHA_DIGEST_LENGTH];
    SHA_CTX ctx;
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Cannot open file for SHA1");
        return;
    }

    SHA1_Init(&ctx);
    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, file)) != 0) {
        SHA1_Update(&ctx, buffer, bytes);
    }
    SHA1_Final(digest, &ctx);
    fclose(file);

    printf("SHA1: ");
    for (int i = 0; i < SHA_DIGEST_LENGTH; i++)
        printf("%02x", digest[i]);
    printf("\n");
}

void calculate_sha256(const char* filename) {
    unsigned char buffer[BUFFER_SIZE];
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256_CTX ctx;
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Cannot open file for SHA256");
        return;
    }

    SHA256_Init(&ctx);
    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, file)) != 0) {
        SHA256_Update(&ctx, buffer, bytes);
    }
    SHA256_Final(digest, &ctx);
    fclose(file);

    printf("SHA256: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        printf("%02x", digest[i]);
    printf("\n");
}

void calculate_sha512(const char* filename) {
    unsigned char buffer[BUFFER_SIZE];
    unsigned char digest[SHA512_DIGEST_LENGTH];
    SHA512_CTX ctx;
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Cannot open file for SHA512");
        return;
    }

    SHA512_Init(&ctx);
    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, file)) != 0) {
        SHA512_Update(&ctx, buffer, bytes);
    }
    SHA512_Final(digest, &ctx);
    fclose(file);

    printf("SHA512: ");
    for (int i = 0; i < SHA512_DIGEST_LENGTH; i++)
        printf("%02x", digest[i]);
    printf("\n");
}

int main() {
    const char* filename = "input.txt";

    printf("Hashing file: %s\n", filename);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    calculate_md5(filename);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("MD5 computation time: %f seconds\n\n", cpu_time_used);

    start = clock();
    calculate_sha1(filename);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("SHA1 computation time: %f seconds\n\n", cpu_time_used);

    start = clock();
    calculate_sha256(filename);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("SHA256 computation time: %f seconds\n\n", cpu_time_used);

    start = clock();
    calculate_sha512(filename);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("SHA512 computation time: %f seconds\n\n", cpu_time_used);

    return 0;
}