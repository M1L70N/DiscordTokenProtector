#pragma once
#include "Config.h"
#include "../Crypto/Crypto.h"
#include "../Crypto/CryptoUtils.h"

constexpr auto SECUREKV_FILENAME = L"secure.dat";
constexpr auto SECUREKV_DELIM = ':';
constexpr auto SECUREKV_HEADER = "SKV";

class SecureKV {
public:
	SecureKV();
	~SecureKV();

	void write(const secure_string& key, const secure_string& value, const KeyData& keydata);
	secure_string read(const secure_string& key, const KeyData& keydata);

	using KV = std::pair<secure_string, secure_string>;
	using KVs = std::vector<KV>;

	bool save(const KVs& content, const KeyData& keydata);
	KVs load(const KeyData& keydata);

	void reencrypt(const KeyData& oldKeydata, const KeyData& newKeydata);

	EncryptionType getEncryptionType();

	//NOT thread safe!
	void reopenFile(bool remove = false);
private:
	void openFile();

	std::fstream m_file;
	std::mutex m_high_mutex;
	std::mutex m_low_mutex;
};

inline std::unique_ptr<SecureKV> g_secureKV;