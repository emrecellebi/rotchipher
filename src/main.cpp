#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

char shift_cipher(char ch, int shift)
{
	if(ch >= 'a' && ch <= 'z')
	{
		char lower[] = "abcdefghijklmnopqrstuvwxyz";
		int idx = -1;
		for(size_t i = 0; i < strlen(lower); i++)
			if(lower[i] == ch) idx = i;
		return lower[(idx + shift) % 26];
	}
	
	if(ch >= 'A' && ch <= 'Z')
	{
		char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		int idx = -1;
		for(size_t i = 0; i < strlen(upper); i++)
			if(upper[i] == ch) idx = i;
		return upper[(idx + shift) % 26];
	}
	return ch;
}

char* rot_encrypt(const char* text, int shift)
{
	size_t len = strlen(text);
	char* buffer = (char*)malloc(len + 1);
	buffer[0] = '\0';
	
	int s = ((shift % 26) + 26) % 26;
	for(size_t i = 0; i <= len; i++)
		sprintf(buffer + strlen(buffer), "%c", shift_cipher(text[i], s));
	return buffer;
}

char* rot_decrypt(const char* text, int shift)
{
	return rot_encrypt(text, -shift);
}

void rot_bruteforce(const char* text)
{
	for(int i = 0; i < 26; i++)
	{
		char* dec = rot_decrypt(text, i);
		printf("Force: %d Decrypt: %s\n", i, dec);
	}
}

void help()
{
	printf("\nCopyright (c) 2012-2025 Emre Celebi\n\n");
	printf("Usage: rotchipher [-options] <parameters>\n");
	printf("  -d, --decrypt  <str> # Decrypt Text\n");
	printf("  -e, --encrypt  <str> # Encrypt Text\n");
	printf("  -f, --force    <str> # Brute Force\n");
	printf("  -r, --rotate   <int> # Shift (default: 12)\n");
	printf("  -v, --version        # Version\n");
	printf("  -h, --help           # Help\n");
}

int main(int argc, char** argv)
{
	int opt;
    int shift = 12;
    const char* encrypt_val = nullptr;
    const char* decrypt_val = nullptr;
    const char* force_val = nullptr;

    static struct option long_options[] = {
        {"rotate",  required_argument, 0, 'r'},
        {"encrypt", required_argument, 0, 'e'},
        {"decrypt", required_argument, 0, 'd'},
        {"force",   required_argument, 0, 'f'},
        {"help",    no_argument,       0, 'h'},
        {"version", no_argument,       0, 'v'},
        {0,0,0,0}
    };

    while((opt = getopt_long(argc, argv, "r:e:d:f:hv", long_options, nullptr)) != -1)
	{
        switch(opt)
		{
            case 'r':
                shift = atoi(optarg);
                break;
            case 'e':
                encrypt_val = optarg;
                break;
            case 'd':
                decrypt_val = optarg;
                break;
            case 'f':
                force_val = optarg;
                break;
            case 'h':
                help();
                break;
            case 'v':
                printf("\nrotchipher version: 0.0.1 Pre-Alpha\n");
				printf("Last revised: 28th Oct 2025\n");
				printf("The last version is always avaible\n");
				printf("Created By Emre Celebi\n");
                break;
            case '?': // getopt_long already prints an error
            default:
                return 1;
        }
    }
	
	if(argc <= 1)
	{
		printf("rotchipher : No command specified. Use 'rotchipher -h or --help' for a detailed command list");
	}
	
	if(shift >= 26)
		shift = 25;
	
	if(shift <= 0)
		shift = 1;

    if(encrypt_val)
	{
        char* enc = rot_encrypt(encrypt_val, shift);
        printf("Encrypt: %s\n", enc);
        free(enc);
    }
    
	if(decrypt_val)
	{
        char* dec = rot_decrypt(decrypt_val, shift);
        printf("Decrypt: %s\n", dec);
        free(dec);
    }
	
    if(force_val)
	{
        rot_bruteforce(force_val);
    }
	
	return 0;
}