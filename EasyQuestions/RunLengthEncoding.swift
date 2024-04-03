
func runLengthEncoding(_ string: String) -> String {
    var encoded = ""
    var counter = 0
    var prev = string.first!
    for letter in string {
       if letter != prev || counter == 9 {
        encoded.append(String(counter) + String(prev))
        counter = 1
       } else {
        counter += 1
       }
       prev = letter
    }
    encoded.append(String(counter) + String(prev))
    return encoded
}


let test = "AAAAAAAAAAAAABBCCCCDD"
print(runLengthEncoding(test))