" local vimrc file
set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab

set colorcolumn=80
highlight ColorColumn ctermbg=darkgray

"augroup project
"  autocmd!
"  autocmd BufRead,BufNewFile *.h,*.c set filetype=c.doxygen
"augroup END

let &path.=".,include,src,header,src/include,/usr/include/AL,/usr/include/**"
