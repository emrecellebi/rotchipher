# rotchipher

```bash
Usage: rotchipher [-options] <parameters>
  -d, --decrypt  <str> # Decrypt Text
  -e, --encrypt  <str> # Encrypt Text
  -f, --force    <str> # Brute Force
  -r, --rotate   <int> # Shift (default: 12)
  -v, --version        # Version
  -h, --help           # Help
```

```bash
rotchipher -e "Hello World!" -r 13       # Encrypt: Uryyb Jbeyq!
rotchipher -d "Uryyb Jbeyq!" -r 13       # Encrypt: Hello World!

rotchipher -e "Hello World!"       # Encrypt: Tqxxa Iadxp!
rotchipher -d "Tqxxa Iadxp!"       # Encrypt: Hello World!

rotchipher -f "Uryyb Jbeyq!"

# Force: 0 Decrypt: Uryyb Jbeyq!
# Force: 1 Decrypt: Tqxxa Iadxp!
# Force: 2 Decrypt: Spwwz Hzcwo!
# Force: 3 Decrypt: Rovvy Gybvn!
# Force: 4 Decrypt: Qnuux Fxaum!
# Force: 5 Decrypt: Pmttw Ewztl!
# Force: 6 Decrypt: Olssv Dvysk!
# Force: 7 Decrypt: Nkrru Cuxrj!
# Force: 8 Decrypt: Mjqqt Btwqi!
# Force: 9 Decrypt: Lipps Asvph!
# Force: 10 Decrypt: Khoor Zruog!
# Force: 11 Decrypt: Jgnnq Yqtnf!
# Force: 12 Decrypt: Ifmmp Xpsme!
# Force: 13 Decrypt: Hello World!
# Force: 14 Decrypt: Gdkkn Vnqkc!
# Force: 15 Decrypt: Fcjjm Umpjb!
# Force: 16 Decrypt: Ebiil Tloia!
# Force: 17 Decrypt: Dahhk Sknhz!
# Force: 18 Decrypt: Czggj Rjmgy!
# Force: 19 Decrypt: Byffi Qilfx!
# Force: 20 Decrypt: Axeeh Phkew!
# Force: 21 Decrypt: Zwddg Ogjdv!
# Force: 22 Decrypt: Yvccf Nficu!
# Force: 23 Decrypt: Xubbe Mehbt!
# Force: 24 Decrypt: Wtaad Ldgas!
# Force: 25 Decrypt: Vszzc Kcfzr!

```