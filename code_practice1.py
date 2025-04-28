import os 
from cryptography.hazmat.primitives.ciphers import algorithms
from cryptography.hazmat.primitives.ciphers import Cipher, modes
from cryptography.hazmat.backends import default_backend
import time

data = os.urandom(1024 * 1024)

key_aes = os.urandom(32)  # AES-256
iv_aes = os.urandom(16)

key_des = os.urandom(24)  # TripleDES
iv_des = os.urandom(8)

def encrypt_data(data, key, iv, algorithm):
    cipher = Cipher(algorithm(key), modes.CBC(iv), backend=default_backend())
    encryptor = cipher.encryptor()
    padded_data = data + b'\0' * (algorithm.block_size // 8 - (len(data) % (algorithm.block_size // 8)))
    ciphertext = encryptor.update(padded_data) + encryptor.finalize()
    return ciphertext

start_aes = time.time()
encrypted_aes = encrypt_data(data, key_aes, iv_aes, algorithms.AES)
end_aes = time.time()

start_des = time.time()
encrypted_des = encrypt_data(data, key_des, iv_des, algorithms.TripleDES)
end_des = time.time()

print(f"زمان رمزنگاری با AES: {end_aes - start_aes:.6f} ثانیه")
print(f"زمان رمزنگاری با 3DES: {end_des - start_des:.6f} ثانیه")
