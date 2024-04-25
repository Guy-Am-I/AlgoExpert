func commonCharacters(_ strings: [String]) -> [String] {
    ///turn each string into a set and return intersection of all
    return strings.reduce(into: Set(strings.first!),
    { (commonChars, str) in
        commonChars = commonChars.intersection(str)
    }).map { String($0) }   
}

let test = ["abc", "bcd", "cbad"]
print (commonCharacters(test))