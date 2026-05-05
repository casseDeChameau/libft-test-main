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

| Function | Toggle | Entry format |
|---|---|---|
| `ft_atoi` | ✓ | `./test.out ft_atoi 1 "42"` |
| `ft_bzero` | ✓ | `./test.out ft_bzero 1 "hello" 3` |
| `ft_calloc` | ✓ | `./test.out ft_calloc 1 5 4` |
| `ft_isalnum` | ✓ | `./test.out ft_isalnum 1 65` |
| `ft_isalpha` | ✓ | `./test.out ft_isalpha 1 65` |
| `ft_isascii` | ✓ | `./test.out ft_isascii 1 65` |
| `ft_isdigit` | ✓ | `./test.out ft_isdigit 1 48` |
| `ft_isprint` | ✓ | `./test.out ft_isprint 1 32` |
| `ft_itoa` | ✗ | `./test.out ft_itoa "-42"` |
| `ft_memchr` | ✓ | `./test.out ft_memchr 1 "hello" 108 5` |
| `ft_memcmp` | ✓ | `./test.out ft_memcmp 1 "abc" "abc" 3` |
| `ft_memcpy` | ✓ | `./test.out ft_memcpy 1 "dst" "src" 3` |
| `ft_memmove` | ✓ | `./test.out ft_memmove 1 "dst" "src" 3` |
| `ft_memset` | ✓ | `./test.out ft_memset 1 "hello" 42 3` |
| `ft_putchar_fd` | ✗ | `./test.out ft_putchar_fd outfile.txt "A"` |
| `ft_putstr_fd` | ✗ | `./test.out ft_putstr_fd outfile.txt "hello"` |
| `ft_putendl_fd` | ✗ | `./test.out ft_putendl_fd outfile.txt "hello"` |
| `ft_putnbr_fd` | ✗ | `./test.out ft_putnbr_fd outfile.txt 42` |
| `ft_split` | ✗ | `./test.out ft_split "hello world" " " 2` |
| `ft_strchr` | ✓ | `./test.out ft_strchr 1 "hello" 108` |
| `ft_strdup` | ✓ | `./test.out ft_strdup 1 "hello"` |
| `ft_striteri` | ✗ | `./test.out ft_striteri "hello"` |
| `ft_strjoin` | ✗ | `./test.out ft_strjoin "hello" " world"` |
| `ft_strlcat` | ✓ | `./test.out ft_strlcat 1 "hello" " world" 10` |
| `ft_strlcpy` | ✓ | `./test.out ft_strlcpy 1 "dst" "src" 4` |
| `ft_strlen` | ✓ | `./test.out ft_strlen 1 "hello"` |
| `ft_strmapi` | ✗ | `./test.out ft_strmapi "hello"` |
| `ft_strncmp` | ✓ | `./test.out ft_strncmp 1 "abc" "abd" 3` |
| `ft_strnstr` | ✓ | `./test.out ft_strnstr 1 "hello world" "world" 11` |
| `ft_strrchr` | ✓ | `./test.out ft_strrchr 1 "hello" 108` |
| `ft_strtrim` | ✗ | `./test.out ft_strtrim "  hello  " " "` |
| `ft_substr` | ✗ | `./test.out ft_substr "hello world" 6 5` |
| `ft_tolower` | ✓ | `./test.out ft_tolower 1 65` |
| `ft_toupper` | ✓ | `./test.out ft_toupper 1 97` |
| `ft_lstnew` | ✗ | `./test.out ft_lstnew "hello"` |
| `ft_lstadd_front` | ✗ | `./test.out ft_lstadd_front "head" "new"` |
| `ft_lstadd_back` | ✗ | `./test.out ft_lstadd_back "head" "new"` |
| `ft_lstsize` | ✗ | `./test.out ft_lstsize 5` |
| `ft_lstlast` | ✗ | `./test.out ft_lstlast 5` |
| `ft_lstdelone` | ✗ | `./test.out ft_lstdelone "hello"` |
| `ft_lstclear` | ✗ | `./test.out ft_lstclear 5` |
| `ft_lstiter` | ✗ | `./test.out ft_lstiter 5` |
| `ft_lstmap` | ✗ | `./test.out ft_lstmap 5` |

---

## Notes

- `fd` functions write to a file — use `cat outfile.txt` to see the result
- `ft_putendl_fd` appends a newline — use `cat -e outfile.txt` to verify
- Linked list tests use `build_lst(n)` which generates a list of `n` nodes with letters `a`→`z` as content
- The toggle `0=lib|1=ft` applies only to functions that have a libc equivalent
