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
| `ft_atoi` | ✓ | `ft_atoi 1 "42"` | `ft_atoi: 42` |
| `ft_bzero` | ✓ | `ft_bzero 1 "hello" 3` | `[0]: 0` `[1]: 0` `[2]: 0` |
| `ft_calloc` | ✓ | `ft_calloc 1 3 4` | `[0]: 0` ... `[11]: 0` |
| `ft_isalnum` | ✓ | `ft_isalnum 1 65` | `ft_isalnum: 1` |
| `ft_isalpha` | ✓ | `ft_isalpha 1 65` | `ft_isalpha: 1` |
| `ft_isascii` | ✓ | `ft_isascii 1 65` | `ft_isascii: 1` |
| `ft_isdigit` | ✓ | `ft_isdigit 1 48` | `ft_isdigit: 1` |
| `ft_isprint` | ✓ | `ft_isprint 1 32` | `ft_isprint: 1` |
| `ft_itoa` | ✗ | `ft_itoa "-42"` | `res: -42` |
| `ft_memchr` | ✓ | `ft_memchr 1 "hello" 108 5` | `ft_memchr: llo` |
| `ft_memcmp` | ✓ | `ft_memcmp 1 "abc" "abc" 3` | `ft_memcmp: 0` |
| `ft_memcpy` | ✓ | `ft_memcpy 1 "dst" "src" 3` | `ft_memcpy: src` |
| `ft_memmove` | ✓ | `ft_memmove 1 "dst" "src" 3` | `ft_memmove: src` |
| `ft_memset` | ✓ | `ft_memset 1 "hello" 42 3` | `ft_memset: ***lo` |
| `ft_putchar_fd` | ✗ | `ft_putchar_fd outfile.txt "A"` | `cat outfile.txt` → `A` |
| `ft_putstr_fd` | ✗ | `ft_putstr_fd outfile.txt "hello"` | `cat outfile.txt` → `hello` |
| `ft_putendl_fd` | ✗ | `ft_putendl_fd outfile.txt "hello"` | `cat -e outfile.txt` → `hello$` |
| `ft_putnbr_fd` | ✗ | `ft_putnbr_fd outfile.txt 42` | `cat outfile.txt` → `42` |
| `ft_split` | ✗ | `ft_split "hello world" " " 2` | `hello` `world` |
| `ft_strchr` | ✓ | `ft_strchr 1 "hello" 108` | `ft_strchr: llo` |
| `ft_strdup` | ✓ | `ft_strdup 1 "hello"` | `orig value: hello` `dup value: hello` `different addresses` |
| `ft_striteri` | ✗ | `ft_striteri "hello"` | `HELLO` |
| `ft_strjoin` | ✗ | `ft_strjoin "hello" " world"` | `ft_strjoin: hello world` |
| `ft_strlcat` | ✓ | `ft_strlcat 1 "hello" " world" 10` | `ft_strlcat: 11` |
| `ft_strlcpy` | ✓ | `ft_strlcpy 1 "dst" "src" 4` | `ft_strlcpy: src` |
| `ft_strlen` | ✓ | `ft_strlen 1 "hello"` | `ft: 5` `lib: 5` |
| `ft_strmapi` | ✗ | `ft_strmapi "hello"` | `HELLO` |
| `ft_strncmp` | ✓ | `ft_strncmp 1 "abc" "abd" 3` | `ft: -1` `lib: -1` |
| `ft_strnstr` | ✓ | `ft_strnstr 1 "hello world" "world" 11` | `strnstr: world` |
| `ft_strrchr` | ✓ | `ft_strrchr 1 "hello" 108` | `ft: llo` |
| `ft_strtrim` | ✗ | `ft_strtrim "  hello  " " "` | `result: hello` |
| `ft_substr` | ✗ | `ft_substr "hello world" 6 5` | `world` |
| `ft_tolower` | ✓ | `ft_tolower 1 65` | `ft_tolower: a` |
| `ft_toupper` | ✓ | `ft_toupper 1 97` | `ft_toupper: A` |
| `ft_lstnew` | ✗ | `ft_lstnew "hello"` | `content: hello` `next: 0x0` |
| `ft_lstadd_front` | ✗ | `ft_lstadd_front "head" "new"` | `head: new` |
| `ft_lstadd_back` | ✗ | `ft_lstadd_back "head" "new"` | `last: new` |
| `ft_lstsize` | ✗ | `ft_lstsize 5` | `size: 5` |
| `ft_lstlast` | ✗ | `ft_lstlast 5` | `last: a` |
| `ft_lstdelone` | ✗ | `ft_lstdelone "hello"` | `lstdelone: ok` |
| `ft_lstclear` | ✗ | `ft_lstclear 5` | `lstclear: ok` |
| `ft_lstiter` | ✗ | `ft_lstiter 5` | `from *f> e` ... `from *f> a` |
| `ft_lstmap` | ✗ | `ft_lstmap 5` | `from *f> E` ... `from *f> A` |

---

## Notes

- `fd` functions write to a file — use `cat outfile.txt` to see the result
- `ft_putendl_fd` appends a newline — use `cat -e outfile.txt` to verify
- Linked list tests use `build_lst(n)` which generates a list of `n` nodes with letters `a`→`z` as content
- The toggle `0=lib|1=ft` applies only to functions that have a libc equivalent
