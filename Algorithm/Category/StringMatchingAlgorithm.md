# 字符串匹配算法

## Brute Force(BF)算法

每轮循环，两字符串在`pos`处对齐，分别匹配模式串之后的内容，如有差异，则立即跳出，`pos`向前进一位，进行下一轮匹配，直到`pos`到达两字符串长度之差的位置处。

```c++
class BF
{
public:
    int solve(const string &mstr, const string &pstr)
    {
        int p_len = pstr.length(), det = mstr.length() - p_len;
        if (det < 0)
            return -1;
        if (pstr.empty())
            return 0;

        int pos, m, p;
        for (pos = 0; pos <= det; ++pos)
        {
            for (p = 0, m = pos; p < p_len; ++p, ++m)
                if (pstr[p] != mstr[m])
                    break;
            if (p == p_len)
                return pos;
        }
        return -1;
    }
};
```

## Knuth-Morris-Pratt(KMP)算法

因为BF算法在遇到不匹配的情况直接跳出并归位，将之前的信息都“删掉”了，因此KMP算法改进了这一方面，它利用不匹配字符的前面那一段字符的最长前后缀来尽可能地跳过最大的距离。

KMP算法的核心，是一个被称为部分匹配表(Partial Match Table)的数组。

先引入前缀集合和后缀集合的概念，然后介绍PMT的生成。对字符串A和B来说，如果存在A=B+K(K是任意非空字符串)，那么B就是A的前缀，如果存在A=K+B(K是任意非空字符串)，那么B就是A的前缀。例如，`A = "Jhon"`的所有前缀为`{"J", "Jh", "Jho"}`，所有后缀为`{"n", "on", "hon"}`。这样构成的两个集合被称为字符串A的前缀集合和后缀集合。

**PMT中的值是字符串的前缀集合与后缀集合的交集中最长元素的长度**。比如，字符串`A = "abcabc"`，它的前缀集合为`{"a", "ab", "abc", "abca", "abcab"}`，后缀集合为`{"c", "bc", "abc", "cabc", "bcabc"}`，则这两个集合的交集为`{"abc"}`，交集内最长的元素为`"abc"`，长度为3，故对于字符串A来说它在PMT表中的值即为3。

最后来解释PMT表在KMP算法中的使用方法。例如在`"A = abcabaabcabc"`中查找`"B = abcabc"`，则先得出`"abcabc"`的PMT表，如下:

| char  | a    | b    | c    | a    | b    | c    |
| ----- | ---- | ---- | ---- | ---- | ---- | ---- |
| index | 0    | 1    | 2    | 3    | 4    | 5    |
| value | 0    | 0    | 0    | 1    | 2    | 3    |

当我们进行匹配时有

```
     j
     ↓
abcabaabcabc
abcabc
     ↑
     i
```

可以发现`i = 5`处不匹配，那么`A[j]`之前的`PMT[i - 1]`位一定与模式串的`0`至`PMT[i - 1]`位是相同的，这是因为，在`j`处不匹配，说明从`j - i`至`j - 1`这一部分是和模式串的`0`至`i-1`相匹配，而正好可以应用`PTM[i-1]`来跳过相应次数的比较，即得到

```
     j
     ↓
abcabaabcabc
   abcabc
     ↑
     i
```

因为从零计数的缘故这里我们采用如下形式的PMT表，增加一行`next`，由`value`向右偏移一位得到，且第零位置为-1，方便我们进入下一轮循环。

| char  | a    | b    | c    | a    | b    | c    |
| ----- | ---- | ---- | ---- | ---- | ---- | ---- |
| index | 0    | 1    | 2    | 3    | 4    | 5    |
| value | 0    | 0    | 0    | 1    | 2    | 3    |
| next  | -1   | 0    | 0    | 0    | 1    | 2    |

那么我们怎样快速得到`next`数组呢？这里可以很容易看出这一数组是由模式串及其自身前缀进行匹配得到的。(`next[0]`默认为-1)

例如

```
 i
 ↓
abcabc
 abcabc
 ↑
 j
next[1] = j = 0

     i
     ↓
abcabc
   abcabc
     ↑
     j
next[5] = j =3
```

```c++
class Solution {
public:
    int strStr(string m_str, string p_str) {
        if (p_str == "") return 0;
        if (m_str.length() < p_str.length()) return -1;
        
        vector<int> next(p_str.length() + 1, -1);
        int m, p;
        // get next array
        m = 0, p = -1;
        while (m < p_str.length()) {
            while (p != -1 && p_str[p] != p_str[m]) p = next[p];
            ++p;
            ++m;
            next[m] = p;
        }
        m = 0, p = 0;
        while (m < m_str.length()) {
            cout << m << " " << p << endl;
            while (p != -1 && p_str[p] != m_str[m]) p = next[p];
            ++m;
            ++p;
            if (p == p_str.length()) return m - p;
        }

        return -1;
    }
};
```

## Boyer-Moore(BM)算法

Boyer-Moore算法是一种基于后缀匹配的模式串匹配算法，后缀匹配就是模式串从右到左开始比较，但模式串的移动还是从左到右的。字符串匹配的关键就是模式串的如何移动才是最高效的，Boyer-Moore为了做到这点定义了两个规则：坏字符规则和好后缀规则。

```
坏字符
  ↓
abaabcabc
abcabc
   ↑↑↑
  好后缀
```

1. 坏字符规则

- 当坏字符没有出现在模式串中，则将模式串移动到坏字符的下一个字符，继续匹配：

```
坏字符
  ↓
abfabcabc
bbbabc
移动后
abfabcabc
 bbbabc
```

- 如果坏字符出现在模式串中，则将模式串最靠近好后缀的坏字符（当然这个实现就有点繁琐）与母串的坏字符对齐。

```
坏字符
  ↓
abaabcabc
abcabc
移动后
abaabcabc
abcabc
```

2. 好后缀规则

- 模式串中存在子串匹配上好后缀，此时移动模式串，让该子串与好后缀对齐即可，如果超过一个子串匹配上好后缀，则选择最靠近好后缀的子串对齐。

```
abaabcabc
abcabc
   ↑↑↑
  好后缀
移动后
abaabcabc
   abcabc
```
- 模式串中没有子串匹配上好后缀，此时需要寻找模式串的一个最长前缀，且该前缀等于好后缀的后缀，寻找到该前缀后，让该前缀和好后缀对齐即可。

```
abaabcabc
 bcabc
   ↑↑↑
  好后缀
移动后
abaabcabc
    bcabc
```

- 模式串中没有子串匹配上好后缀，并且在模式串中找不到前缀等于好后缀的后缀。此时，直接移动模式串到好后缀的下一个字符。

```
abaabcabckkkabc
kkkabc
   ↑↑↑
  好后缀
移动后
abaabcabckkkabc
      kkkabc
```

具体实现如下，为满足以上规则我们要预处理模式串，分别获取两个辅助数列`Delta1`和`Delta2`，前者是为了满足坏字符规则，后者为满足好后缀规则。

- `Delta1`在这里为方便，考虑文本只有ASCII因此直接声明一个256大小的数组，模式串中从右侧开始第一次出现的字符至右侧的距离即为`Delta1[pstr[i]]`的值，其余均为模式串的长度。
- `Delta2`中`case 1`是考虑坏字符后的好后缀的相同最长前缀，求取文本串的匹配指针前进的步数，其等式为**与最长前缀相同的后缀开始坐标加上好后缀的长度**，`case 2`是考虑坏字符后的好后缀不存在相同最长前缀时但在模式串中**其他位置**出现，其等式为**在其他位置出现的好后缀的长度加上出现位置的尾部距模式串尾部的长度**。

```c++
class BM
{
private:
    const static int alpha_num = 256;
    vector<int> GetDelta1(const string &pstr)
    {
        int p_len = pstr.length();
        vector<int> Delta1(alpha_num, p_len);
        for (int i = 0; i < p_len - 1; ++i)
            Delta1[pstr[i]] = p_len - 1 - i;
        return Delta1;
    }
    vector<int> GetDelta2(const string &pstr)
    {
        int p_len = pstr.length();
        vector<int> Delta2(p_len);
        vector<int> SuffixLen(p_len);
        // case 1: ( the longest prefix-same suffix head position ) + ( the mismatching postion - tail )
        int last_suffix_index;
        for (int p = p_len - 1; p >= 0; --p)
        {
            int i, j;
            for (i = 0, j = p + 1; j < p_len; ++j, ++i)
                if (pstr[i] != pstr[j])
                    break;
            if (j == p_len)
                last_suffix_index = p + 1;
            Delta2[p] = last_suffix_index + (p_len - 1 - p);
        }
        
        // case 2: suffix appears at somewhere else in the pattern string
        // len = suffix's length
        // p_len - 1 - p = the mismatching postion - tail

        for (int p = 0; p < p_len - 1; ++p)
        {
            int len;
            for (len = 0; pstr[p - len] == pstr[p_len - 1 - len] && len < p; ++len)
                ;
            if (pstr[p - len] != pstr[p_len - 1 - len])
            {
                Delta2[p_len - 1 - len] = p_len - 1 - p + len;
            }
        }

        return Delta2;
    }

public:
    vector<int> solve(const string &mstr, const string &pstr)
    {
        int p_len = pstr.length(), m_len = mstr.length();
        if (m_len - p_len < 0)
            throw "Mathing string is shorter than pattern string.";
        if (pstr.empty())
            return {};
        vector<int> Delta1 = GetDelta1(pstr);
        vector<int> Delta2 = GetDelta2(pstr);
        vector<int> ans;
        int m = p_len - 1, p;
        while (m < m_len)
        {
            p = p_len - 1;
            while (p >= 0 && mstr[m] == pstr[p])
            {
                --m;
                --p;
            }
            if (p < 0)
            {
                //save an answer
                ans.push_back(m + 1);
                //move forward a distance equal to the length of a pattern string
                m += Delta2[0] + 1;
            }
            else
                m += max(Delta1[mstr[m]], Delta2[p]);
        }
        return ans;
    }
};
```

**注：**

1. 在`c++17`中加入了BM接口，定义在头文件`functional`中，适用于` std::search `的搜索器 (Searcher) 的重载，实现了 Boyer-Moore 字符串搜索算法。

```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
 
int main()
{
    std::string in = "Lorem ipsum dolor sit amet, consectetur adipiscing elit,";
    std::string needle = "pisci";
    auto it = std::search(in.begin(), in.end(),
                   std::boyer_moore_searcher(
                       needle.begin(), needle.end()));
    if(it != in.end())
        std::cout << "The string " << needle << " found at offset "
                  << it - in.begin() << '\n';
    else
        std::cout << "The string " << needle << " not found\n";
}
```

2. C语言实现

```c
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_LEN 256
#define NOT_FOUND patlen
#define max(a, b) ((a < b) ? b : a)

#define DEBUG

int chars_compared;

// delta1 table: delta1[c] contains the distance between the last
// character of pat and the rightmost occurrence of c in pat.
// If c does not occur in pat, then delta1[c] = patlen.
// If c is at string[i] and c != pat[patlen-1], we can
// safely shift i over by delta1[c], which is the minimum distance
// needed to shift pat forward to get string[i] lined up
// with some character in pat.
// this algorithm runs in alphabet_len+patlen time.
void make_delta1(int *delta1, uint8_t *pat, int32_t patlen)
{
    int i;
#ifdef DEBUG
    int j;
    int delta1_chars[patlen];
    int max_chars = 0;
    bool is_matched = false;
#endif

    for (i = 0; i < ALPHABET_LEN; i++)
    {
        delta1[i] = NOT_FOUND;
    }
    for (i = 0; i < patlen - 1; i++)
    {
        delta1[pat[i]] = patlen - 1 - i;
#ifdef DEBUG
        is_matched = false;
        for (j = 0; j <= max_chars; j++)
        {
            if (delta1_chars[j] == pat[i])
            {
                is_matched = true;
            }
        }
        if (is_matched == false)
        {
            delta1_chars[max_chars] = pat[i];
            max_chars++;
        }
#endif
    }
#ifdef DEBUG
    int t;
    printf("\n");
    for (t = 0; t < max_chars; t++)
        printf("delta1[%c] = %d\n", delta1_chars[t], delta1[delta1_chars[t]]);
    printf("delta1[other] = %d\n", NOT_FOUND);
#endif
}

// true if the suffix of word starting from word[pos] is a prefix
// of word
int is_prefix(uint8_t *word, int wordlen, int pos)
{
    int i;
    int suffixlen = wordlen - pos;

    for (i = 0; i < suffixlen; i++)
    {
        if (word[i] != word[pos + i])
        {
            return 0;
        }
    }
    return 1;
}

// length of the longest suffix of word ending on word[pos].
// suffix_length("dddbcabc", 8, 4) = 2
int suffix_length(uint8_t *word, int wordlen, int pos)
{
    int i;
    // increment suffix length i to the first mismatch or beginning
    // of the word
    for (i = 0; (word[pos - i] == word[wordlen - 1 - i]) && (i < pos); i++)
        ;
    return i;
}

// delta2 table: given a mismatch at pat[pos], we want to align
// with the next possible full match could be based on what we
// know about pat[pos+1] to pat[patlen-1].
//
// In case 1:
// pat[pos+1] to pat[patlen-1] does not occur elsewhere in pat,
// the next plausible match starts at or after the mismatch.
// If, within the substring pat[pos+1 .. patlen-1], lies a prefix
// of pat, the next plausible match is here (if there are multiple
// prefixes in the substring, pick the longest). Otherwise, the
// next plausible match starts past the character aligned with
// pat[patlen-1].
//
// In case 2:
// pat[pos+1] to pat[patlen-1] does occur elsewhere in pat. The
// mismatch tells us that we are not looking at the end of a match.
// We may, however, be looking at the middle of a match.
//
// The first loop, which takes care of case 1, is analogous to
// the KMP table, adapted for a 'backwards' scan order with the
// additional restriction that the substrings it considers as
// potential prefixes are all suffixes. In the worst case scenario
// pat consists of the same letter repeated, so every suffix is
// a prefix. This loop alone is not sufficient, however:
// Suppose that pat is "ABYXCDEYX", and text is ".....ABYXCDEYX".
// We will match X, Y, and find B != E. There is no prefix of pat
// in the suffix "YX", so the first loop tells us to skip forward
// by 9 characters.
// Although superficially similar to the KMP table, the KMP table
// relies on information about the beginning of the partial match
// that the BM algorithm does not have.
//
// The second loop addresses case 2. Since suffix_length may not be
// unique, we want to take the minimum value, which will tell us
// how far away the closest potential match is.
void make_delta2(int *delta2, uint8_t *pat, int32_t patlen)
{
    int p;
    int last_prefix_index = 1;

    // first loop, prefix pattern
    for (p = patlen - 1; p >= 0; p--)
    {
        if (is_prefix(pat, patlen, p + 1))
        {
            last_prefix_index = p + 1;
        }
        delta2[p] = (patlen - 1 - p) + last_prefix_index;
    }

    // this is overly cautious, but will not produce anything wrong
    // second loop, suffix pattern
    for (p = 0; p < patlen - 1; p++)
    {
        int slen = suffix_length(pat, patlen, p);
        printf("%d %d\n", p, slen);
        if (pat[p - slen] != pat[patlen - 1 - slen])
        {
            delta2[patlen - 1 - slen] = patlen - 1 - p + slen;
            // printf("%d %d\n", p, patlen - 1 - p + slen);
        }
    }
#ifdef DEBUG
    int t;
    printf("\n");
    for (t = 0; t < patlen; t++)
    {
        printf("delta2[%c]: %d\n", pat[t], delta2[t]);
    }
#endif
}

uint32_t boyer_moore(uint8_t *string, uint32_t stringlen, uint8_t *pat, uint32_t patlen)
{
    int i;
    int delta1[ALPHABET_LEN];
    int *delta2 = malloc(patlen * sizeof(int));
    make_delta1(delta1, pat, patlen);
    make_delta2(delta2, pat, patlen);
    int n_shifts = 0;
    chars_compared = 0;
#ifdef DEBUG
    printf("\n");
#endif
    i = patlen - 1;
    while (i < stringlen)
    {
        int j = patlen - 1;
        while (j >= 0 && (string[i] == pat[j]))
        {
            --i;
            --j;
            chars_compared++;
        }
        if (j < 0)
        {
            free(delta2);
            return (uint32_t)i + 1;
        }
        chars_compared++;
#ifdef DEBUG
        n_shifts++;
        if (delta1[string[i]] > delta2[j])
        {
            printf("shift #%d, using delta1, shifting by %d\n", n_shifts, delta1[string[i]]);
        }
        else
        {
            printf("shift #%d, using delta2, shifting by %d\n", n_shifts, delta2[j]);
        }
#endif

        i += max(delta1[string[i]], delta2[j]);
    }
    free(delta2);
    return 0;
}

void test(uint8_t *string, uint8_t *pat)
{
    printf("-------------------------------------------------------\n");
    printf("Looking for '%s' in '%s':\n", pat, string);

    uint32_t pos = boyer_moore(string, strlen(string), pat, strlen(pat));
#ifdef DEBUG
    printf("\n");
#endif
    if (pos == 0 && chars_compared != strlen(pat))
        printf("Not Found - ");
    else
        printf("Found at position %u - ", pos);
    printf("%d chars compared.\n", chars_compared);
}

int main(int argc, char const *argv[])
{
    test(".....ABYXCDEYX", "ABYXCDEYX");
    test("WHICH-FINALLY-HALTT-THAT", "TT-THAT");
    test("....ccbc.zbc", "ccbc.zbc");
    test("...........................", "ABYXCDEYX");
    test("..cbcabcabc", "bcabcabc");
    test("..adbdadbda", "adbda");
    test("test is good", "test");
    test("hello", "ll");
    test("elemeeemelemelemklemelemele", "elemele");
    test("mississippi", "issi");
    return 0;
}
```



## Horspool算法

Horspool算法将主串中匹配窗口的最后一个字符跟模式串中的最后一个字符比较。如果相等，继续从后向前对主串和模式串进行比较，直到完全相等或者在某个字符处不匹配为止。如果不匹配，则根据主串匹配窗口中的最后一个字符在模式串中的下一个出现位置将窗口向右移动。

```
      miss
       ↓↓
abcdefghijk
  ighijki
        ↑
移动后
        ↓
abcdefghijk
     ighijki
        ↑
```

对于每个搜索窗口，该算法将窗口内的最后一个字符和模式串中的最后一个字符进行比较。如果相等，则需要进行一个校验过程。该校验过程在搜索窗口中从后向前对文本和模式串进行比较，直到完全相等或者在某个字符处不匹配。无论匹配与否，都将根据字符在模式串中的下一个出现位置将窗口向右移动。

1. 窗口大小与模式串大小相同，窗口内容为文本内容的一部分。

2. 对于窗口而言，每次从后向前匹配，直到全部相等(匹配)，或者遇到不相等。

3. 遇到不相等时，根据窗口中最后一个字符在模式串中的位置，窗口进行移动。如果模式串中有多个相同的字符，选择最后一个字符为准，以避免漏解。

总而言之，Horspool算法算是BM算法的简化版本。

```c++
class BMH
{
private:
    const static int alpha_num = 256;

public:
    int solve(const string &mstr, const string &pstr)
    {
        int p_len = pstr.length(), m_len = mstr.length(), det = m_len - p_len;
        if (det < 0)
            return -1;
        if (pstr.empty())
            return 0;

        vector<int> distance(alpha_num, p_len);
        for (int i = 0; i < p_len - 1; ++i)
            distance[pstr[i]] = p_len - 1 - i;

        int m = 0, p;
        while (m <= det)
        {
            for (p = p_len - 1; p >= 0; --p)
                if (mstr[m + p] != pstr[p])
                    break;
            if (p < 0)
                return m;
            else
                m += distance[mstr[m + p_len - 1]];
        }
        return -1;
    }
};
```

## Sunday算法

Sunday算法是从前往后匹配，在匹配失败时关注的是主串中参加匹配的最末位字符的下一位字符。

如果该字符没有在模式串中出现则直接跳过，即移动位数 = 模式串长度 + 1，否则，其移动位数 = 模式串长度 - 该字符最右出现的位置(以0开始) = 模式串中该字符最右出现的位置到尾部的距离 + 1。

```c++
class Sunday
{
private:
    const static int alpha_num = 256;

public:
    int solve(const string &mstr, const string &pstr)
    {
        int p_len = pstr.length(), m_len = mstr.length(), det = m_len - p_len;
        if (det < 0)
            return -1;
        if (pstr.empty())
            return 0;

        vector<int> distance(alpha_num, p_len);
        for (int i = 0; i < p_len; ++i)
            distance[pstr[i]] = p_len - i;

        int m = 0, p;
        while (m <= det)
        {
            for (p = 0; p < p_len; ++p)
                if (mstr[m + p] != pstr[p])
                    break;
            if (p == p_len)
                return m;
            else
                m += distance[mstr[m + p_len]];
        }
        return -1;
    }
};
```

从实现上来说，可以看出Sunday算法和Horspool算法有很多极其相似的地方。

## Karp-Rabin(KR)算法

Rabin-Karp 算法（也可以叫 Karp-Rabin 算法），由 Richard M. Karp 和 Michael O. Rabin 在 1987 年发表，它也是用来解决多模式串匹配问题的。

它是利用hash函数的特性进行字符串匹配的。 KR算法对模式串和循环中每一次要匹配的子串按一定的hash函数求值，如果hash值相同，才进一步比较这两个串是否真正相等。

```c++
class KR
{
private:
    

public:
    int solve(const string &mstr, const string &pstr)
    {
        int p_len = pstr.length(), m_len = mstr.length(), det = m_len - p_len;
        if (det < 0)
            return -1;
        if (pstr.empty())
            return 0;
        int m_hash = hash(mstr, p_len);
        int p_hash = hash(pstr, p_len);

        int m = 0;
        while (m <= det)
        {
   			if(m_hash == p_hash && pstr.compare(0, p_len - 1, mstr, m, m + p_len -1))
                return m;
            rehash(m_hash);
            ++m;
        }
        return -1;
    }
};
```

