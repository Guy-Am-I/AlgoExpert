func selectionSort(array: inout [Int]) -> [Int] {
    var insertIdx = 0
    while insertIdx < array.count - 1 {
        var min = array[insertIdx]
        var swapIdx = insertIdx
        ///find min in array
        for i in insertIdx..<array.count {
            if array[i] < min {
                min = array[i]
                swapIdx = i
            }
        }
        let temp = array[insertIdx]
        array[insertIdx] = min
        array[swapIdx] = temp
        insertIdx += 1
    }
    return array
}

var arr = [8, 5, 2, 9, 5, 6, 3]
print(selectionSort(array: &arr))