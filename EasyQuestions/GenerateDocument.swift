func generateDocument(_ characters: String, _ document: String) -> Bool {
    var charBank = Array(characters)
    for letter in document {
        if let idx = charBank.firstIndex(of: letter) {
            charBank.remove(at: idx)
        } else { return false }
    }
  return true
}

let characters = "Bste!hetsi ogEAxpelrt x "
let document = "AlgoExpert is the Best!"

print(generateDocument(characters, document))
