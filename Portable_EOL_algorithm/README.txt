具有可移植性的行結尾字元序列演算法函式庫
Portable EOL algorithm

這個函式庫出現的原因是當我發現標準C++函式庫中的getline()函式在Linux平台下不能正確的處理Windows的行結尾字元序列(\r\n)而想辦法整理出來的。