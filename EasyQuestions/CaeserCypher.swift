
func caesarCipherEncryptor(string: String, key: UInt32) -> String {
    /**
    - for every letter in the string, transform into 2 letters 'higher'
    */
    let ALPHABET_SIZ: UInt32 = 26
    let result = string.map { (letter: Character) -> Character in 
        let firstLet = Character("a").asciiValue!
        let offset = (UInt32(letter.asciiValue! - firstLet) + key) % ALPHABET_SIZ
        return Character(UnicodeScalar(firstLet + UInt8(offset)))
    }
    return String(result)
}

let test = "xyz"
print(caesarCipherEncryptor(string: test, key: 2))
print(caesarCipherEncryptor(string: test, key: 5))