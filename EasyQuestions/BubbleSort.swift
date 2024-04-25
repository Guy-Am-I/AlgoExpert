func bubbleSort(array: inout [Int]) -> [Int] {
    ///while not sorted keep bubbling away
    var isSorted = false
    var counter = 0 ///adding counter of sorted items (bubbling largest to end)
    while (!isSorted) {
        isSorted = true
        for i in 0..<array.count-1-counter {
            if array[i] > array[i + 1] {
                let temp = array[i]
                array[i] = array[i+1]
                array[i + 1] = temp
                isSorted = false
            }
        }
        counter += 1
    }
    return array
}
var arr = [8, 5, 2, 9, 5, 6, 3]
print(bubbleSort(array: &arr))