func isPalindrome(_ string: String) -> Bool {
    if string.count <= 1 {
        return true
    }
    let extracted = string.dropFirst().dropLast()
    return string.prefix(1) == string.suffix(1) && 
        isPalindrome(String(extracted))
}

print(isPalindrome("abcdcba"))
print(isPalindrome("abccba"))
print(isPalindrome("abcdecba"))