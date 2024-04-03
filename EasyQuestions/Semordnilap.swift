
func semordnilap(_ words: [String]) -> [[String]] {
    var result: [[String]] = []
    for word in words {
        let rev = String(word.reversed())
        if word != rev, words.contains(rev), !result.contains([rev, word]) {
            result.append([word, rev])
        }
    }
    //remove dups
    return result
}


let test = ["dog", "hello", "desserts", "test", "god", "stressed"]
print(semordnilap(test))
