class Program {
    /// Given an array of at least 3 integers find the 3 largest one
    /// - Parameter array: Integer array, size >= 3
    /// - Returns: Asc Sorted array of the 3 largest numbers in given array
  func findThreeLargestNumbers(array: [Int]) -> [Int] {
    var threeLargest: Array<Int> = [Int.min,Int.min,Int.min]
    ///potentially remove first 3 elemens though it doesnt matter since we sort
    array.forEach({
        ///get index to place sorted
        if $0 > threeLargest[2] {
            threeLargest = Array(threeLargest[1..<3] + [$0])
        } else if $0 > threeLargest[1] {
            threeLargest = Array(threeLargest[1..<2] + [$0] + threeLargest[2..<3])
        } else if $0 > threeLargest[0] {
            threeLargest[0] = $0
        }
    })
    return threeLargest
  }
}
let program = Program()
print(program.findThreeLargestNumbers(array: [141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7]))