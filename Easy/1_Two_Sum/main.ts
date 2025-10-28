function twoSum(nums: number[], target: number): number[] {
  const mapList = new Map<number, number>();

  for (let i = 0; i < nums.length; i++) {
    const diff: number = target - nums[i];

    if (mapList.has(diff)) {
      return [mapList.get(diff)!, i];
    }

    mapList.set(nums[i], i);
  }
  return [];
}

// === 測試區 ===

// ✅ 範例 1
console.log(twoSum([2, 7, 11, 15], 9));  
// 預期輸出: [0, 1] → 因為 nums[0] + nums[1] = 2 + 7 = 9

// ✅ 範例 2
console.log(twoSum([3, 2, 4], 6));       
// 預期輸出: [1, 2] → 因為 nums[1] + nums[2] = 2 + 4 = 6

// ✅ 範例 3
console.log(twoSum([3, 3], 6));          
// 預期輸出: [0, 1]

// ✅ 範例 4
console.log(twoSum([1, 5, 3, 7], 8));    
// 預期輸出: [1, 2] → 5 + 3 = 8

// ✅ 範例 5（找不到組合）
console.log(twoSum([1, 2, 3], 10));      
// 預期輸出: [] → 沒有符合的組合
