func firstNonRepeatingCharacter(_ string: String) -> Int {
    let freq = string.reduce(into: [:], { dict, char in
        dict[char, default: 0] += 1
    })
    for (index, letter) in string.enumerated() {
        if freq[letter] == 1 {
            return index
        }
    }
    return -1
}