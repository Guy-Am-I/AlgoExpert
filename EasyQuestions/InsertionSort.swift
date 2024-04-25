
func insertionSort(array: inout [Int]) -> [Int] {
    /// Write your code here.
    for i in 1..<array.count {
        var j = i

        while j > 0 && array[j] < array[j - 1] {
            let temp = array[j]
            array[j] = array[j - 1]
            array[j-1] = temp
            j -= 1
        }
    }
    return array
}

var arr = [8, 5, 2, 9, 5, 6, 3]
print(insertionSort(array: &arr))