use std::collections::HashMap;
impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut out = Vec::new();
        let mut hash_values = HashMap::new();

        for i in nums {
            if hash_values.contains_key(&i) {
                let val = hash_values.get(&i);
                match val {
                    Some(value) => {
                        hash_values.insert(i, *value + 1);
                    }
                    None => {
                        continue;
                    }
                }
            } else {
                hash_values.insert(i, 1);
            }
        }

        let mut temp: Vec<(&i32, &i32)> = hash_values.iter().collect();
        temp.sort_by(|a, b| b.1.cmp(&a.1));
        let mut index = 0;
        for item in temp {
            if index < k {
                out.push(*item.0);
                index += 1;
            } else {
                break;
            }
        }
        return out;
    }
}
