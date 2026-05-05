# libft-test-main
```
 __         __     ______     ______      
/\ \       /\ \   /\  == \   /\__  _\     
\ \ \____  \ \ \  \ \  __<   \/_/\ \/     
 \ \_____\  \ \_\  \ \_____\    \ \_\     
  \/_____/   \/_/   \/_____/     \/_/     
                                          
 ______   ______     ______     ______    
/\__  _\ /\  ___\   /\  ___\   /\__  _\   
\/_/\ \/ \ \  __\   \ \___  \  \/_/\ \/   
   \ \_\  \ \_____\  \/\_____\    \ \_\   
    \/_/   \/_____/   \/_____/     \/_/   
                                          
 __    __     ______     __     __   __   
/\ "-./  \   /\  __ \   /\ \   /\ "-.\ \  
\ \ \-./\ \  \ \  __ \  \ \ \  \ \ \-.  \ 
 \ \_\ \ \_\  \ \_\ \_\  \ \_\  \ \_\\"\_\
  \/_/  \/_/   \/_/\/_/   \/_/   \/_/ \/_/                               
```
A personal test harness for the [libft](https://github.com/<your_handle>/libft) project. Not submitted with the library — kept separate as it is not allowed for the 42 moulinette.

Each test compares `ft_` implementations against their libc equivalent where one exists, or runs the function directly otherwise.

---

## Setup

```bash
git clone https://github.com/<your_handle>/libft-test-main
cp main.c <path_to_libft>/
cd <path_to_libft>
```

```bash
gcc main.c -L. -lft -o test.out
```

---

## Usage

```bash
./test.out <function_name> <0=lib|1=ft> <args...>
```

`0` runs the libc original, `1` runs your implementation. Not all functions have a libc equivalent — those take arguments directly without the toggle.

---

## Function reference

| Function | Toggle | Entry format | Expected output |
|---|---|---|---|
| `ft_atoi` | ✓ | `ft_atoi 1 "  -2147483648"` | `ft_atoi: -2147483648` |
| `ft_bzero` | ✓ | `ft_bzero 1 "hello" 0` | *(no output — n=0)* |
| `ft_calloc` | ✓ | `ft_calloc 1 0 4` | *(no output — nmemb=0)* |
| `ft_isalnum` | ✓ | `ft_isalnum 1 32` | `ft_isalnum: 0` |
| `ft_isalpha` | ✓ | `ft_isalpha 1 48` | `ft_isalpha: 0` |
| `ft_isascii` | ✓ | `ft_isascii 1 128` | `ft_isascii: 0` |
| `ft_isdigit` | ✓ | `ft_isdigit 1 47` | `ft_isdigit: 0` |
| `ft_isprint` | ✓ | `ft_isprint 1 31` | `ft_isprint: 0` |
| `ft_itoa` | ✗ | `ft_itoa "-2147483648"` | `res: -2147483648` |
| `ft_memchr` | ✓ | `ft_memchr 1 "hello" 122 5` | `ft_memchr: (null)` |
| `ft_memcmp` | ✓ | `ft_memcmp 1 "abc" "abd" 3` | `ft_memcmp: -1` |
| `ft_memcpy` | ✓ | `ft_memcpy 1 "aaaaa" "src" 0` | `ft_memcpy: aaaaa` |
| `ft_memmove` | ✓ | `ft_memmove 1 "hello" "hello" 5` | `ft_memmove: hello` |
| `ft_memset` | ✓ | `ft_memset 1 "hello" 0 3` | `ft_memset: \0\0\0lo` |
| `ft_putchar_fd` | ✗ | `ft_putchar_fd outfile.txt " "` | `cat outfile.txt` → space |
| `ft_putstr_fd` | ✗ | `ft_putstr_fd outfile.txt ""` | `cat outfile.txt` → *(empty)* |
| `ft_putendl_fd` | ✗ | `ft_putendl_fd outfile.txt ""` | `cat -e outfile.txt` → `$` |
| `ft_putnbr_fd` | ✗ | `ft_putnbr_fd outfile.txt -2147483648` | `cat outfile.txt` → `-2147483648` |
| `ft_split` | ✗ | `ft_split "" "z" 0` | `ft_split:` *(empty)* |
| `ft_strchr` | ✓ | `ft_strchr 1 "hello" 0` | `ft_strchr: ` *(points to \0)* |
| `ft_strdup` | ✓ | `ft_strdup 1 ""` | `orig value: ` `dup value: ` `different addresses` |
| `ft_striteri` | ✗ | `ft_striteri ""` | *(empty)* |
| `ft_strjoin` | ✗ | `ft_strjoin "" ""` | `ft_strjoin: ` |
| `ft_strlcat` | ✓ | `ft_strlcat 1 "hello" " world" 3` | `ft_strlcat: 9` |
| `ft_strlcpy` | ✓ | `ft_strlcpy 1 "dst" "hello" 0` | `ft_strlcpy: dst` |
| `ft_strlen` | ✓ | `ft_strlen 1 ""` | `ft: 0` `lib: 0` |
| `ft_strmapi` | ✗ | `ft_strmapi ""` | *(empty)* |
| `ft_strncmp` | ✓ | `ft_strncmp 1 "abc" "abc" 0` | `ft: 0` `lib: 0` |
| `ft_strnstr` | ✓ | `ft_strnstr 1 "hello" "" 5` | `strnstr: hello` |
| `ft_strrchr` | ✓ | `ft_strrchr 1 "hello" 108` | `ft: lo` *(last l)* |
| `ft_strtrim` | ✗ | `ft_strtrim "aahelloaa" "a"` | `result: hello` |
| `ft_substr` | ✗ | `ft_substr "hello" 10 5` | *(empty — start > len)* |
| `ft_tolower` | ✓ | `ft_tolower 1 65` | `ft_tolower: a` |
| `ft_toupper` | ✓ | `ft_toupper 1 122` | `ft_toupper: Z` |
| `ft_lstnew` | ✗ | `ft_lstnew ""` | `content: ` `next: 0x0` |
| `ft_lstadd_front` | ✗ | `ft_lstadd_front "" "new"` | `head: new` |
| `ft_lstadd_back` | ✗ | `ft_lstadd_back "head" ""` | `last: ` |
| `ft_lstsize` | ✗ | `ft_lstsize 0` | `size: 0` |
| `ft_lstlast` | ✗ | `ft_lstlast 1` | `last: a` |
| `ft_lstdelone` | ✗ | `ft_lstdelone ""` | `lstdelone: ok` |
| `ft_lstclear` | ✗ | `ft_lstclear 0` | `lstclear: ok` |
| `ft_lstiter` | ✗ | `ft_lstiter 1` | `from *f> a` |
| `ft_lstmap` | ✗ | `ft_lstmap 1` | `from *f> A` |

---

## Notes

- `fd` functions write to a file — use `cat outfile.txt` to see the result
- `ft_putendl_fd` appends a newline — use `cat -e outfile.txt` to verify
- Linked list tests use `build_lst(n)` which generates a list of `n` nodes with letters `a`→`z` as content
- The toggle `0=lib|1=ft` applies only to functions that have a libc equivalent
