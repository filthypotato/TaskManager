#pragma once

#include <string>

class EncDec
{
public:
	void encrypt();
	void decrypt();

private:
	std::string phrase{}; // passphrase of choice to encrypt file with
};