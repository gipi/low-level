# Vim

## Variables

In order to see variables you can simply use ``:let <variable>`` or
without a variable to see **all** the variables defined.

Variables have also scope (see ``:help internal-variables``)

| Prefix | Description |
|--------|-------------|
| ``g:`` |  global variables |
| ``b:`` |  local buffer variables |
| ``w:`` |  local window variables |
| ``t:`` |  local tab page variables |
| ``s:`` |  script-local variables |
| ``l:`` |  local function variables |
| ``v:`` |  Vim variables |
| ``a:`` |  function argument |

 - [How to view variables in Vim](https://codeyarns.com/2010/11/26/how-to-view-variables-in-vim/)

### Predefined variables


## Environment

| Command | Description |
|---------|-------------|
| ``:abbreviate  `` | list abbreviations |
| ``:args        `` | argument list |
| ``:augroup     `` | augroups |
| ``:autocmd     `` | list auto-commands |
| ``:buffers     `` | list buffers |
| ``:breaklist   `` | list current breakpoints |
| ``:cabbrev     `` | list command mode abbreviations |
| ``:changes     `` | changes |
| ``:cmap        `` | list command mode maps |
| ``:command     `` | list commands |
| ``:compiler    `` | list compiler scripts |
| ``:digraphs    `` | digraphs |
| ``:file        `` | print filename, cursor position and status (like Ctrl-G) |
| ``:filetype    `` | on/off settings for filetype detect/plugins/indent |
| ``:function    `` | list user-defined functions (names and argument lists but not the full code) |
| ``:function Foo`` | user-defined function Foo() (full code list) |
| ``:highlight   `` | highlight groups |
| ``:history c   `` | command history |
| ``:history =   `` | expression history |
| ``:history s   `` | search history |
| ``:history     `` | your commands |
| ``:iabbrev     `` | list insert mode abbreviations |
| ``:imap        `` | list insert mode maps |
| ``:intro       `` | the Vim splash screen, with summary version info |
| ``:jumps       `` | your movements |
| ``:language    `` | current language settings |
| ``:let         `` | all variables |
| ``:let FooBar  `` | variable FooBar |
| ``:let g:      `` | global variables |
| ``:let v:      `` | Vim variables |
| ``:list        `` | buffer lines (many similar commands) |
| ``:lmap        `` | language mappings (set by keymap or by lmap) |
| ``:ls          `` | buffers |
| ``:ls!         `` | buffers, including "unlisted" buffers |
| ``:map!        `` | Insert and Command-line mode maps (imap, cmap) |
| ``:map         `` | Normal and Visual mode maps (nmap, vmap, xmap, smap, omap) |
| ``:map<buffer> `` | buffer local Normal and Visual mode maps |
| ``:map!<buffer>`` | buffer local Insert and Command-line mode maps |
| ``:marks       `` | marks |
| ``:menu        `` | menu items |
| ``:messages    `` | message history |
| ``:nmap        `` | Normal-mode mappings only |
| ``:omap        `` | Operator-pending mode mappings only |
| ``:print       `` | display buffer lines (useful after :g or with a range) |
| ``:reg         `` | registers |
| ``:scriptnames `` | all scripts sourced so far |
| ``:set all     `` | all options, including defaults |
| ``:setglobal   `` | global option values |
| ``:setlocal    `` | local option values |
| ``:set         `` | options with non-default value |
| ``:set termcap `` | list terminal codes and terminal keys |
| ``:smap        `` | Select-mode mappings only |
| ``:spellinfo   `` | spellfiles used |
| ``:syntax      `` | syntax items |
| ``:syn sync    `` | current syntax sync mode |
| ``:tabs        `` | tab pages |
| ``:tags        `` | tag stack contents |
| ``:undolist    `` | leaves of the undo tree |
| ``:verbose     `` | show info about where a map or autocmd or function is defined |
| ``:version     `` | list version and build options |
| ``:vmap        `` | Visual and Select mode mappings only |
| ``:winpos      `` | Vim window position (gui) |
| ``:xmap        `` | visual mode maps only |

## Registers

There are ten types of registers (see ``:help registers``):

 1. The unnamed register ``""``
 2. 10 numbered registers ``"0`` to ``"9``
 3. The small delete register "-
 4. 26 named registers ``"a`` to ``"z`` or ``"A`` to ``"Z``
 5. Three read-only registers ``":`` (most recent executed command line), ``".`` (last inserted text) and ``"%`` (relative file path)
 6. Alternate buffer register ``"#``
 7. The expression register ``"=``
 8. The selection and drop registers ``"*``, ``"+`` and ``"~`` 
 9. The black hole register ``"_``
 10. Last search pattern register ``"/``


## Commands

| Command | Description | Binding |
|---------|-------------|---------|
| ``:argdo`` | execute action on each file passed as argument when ``vim`` was started | |
| ``:bufdo`` | execute action on each buffer | |
| ``:diffthis`` | make the current window part of the diff window | |
| ``:echom[sg]`` | print message| |
| ``:exe[cute]`` | execute command passed as string | |
| ``:mks``      | save session to disk | |
| ``:norm[al]`` | run command in normal mode | |
| ``:r[ead] !{cmd}`` | execute ``{cmd}`` and insert the standard output | |
| ``:scrollbind`` | Binds two or more windows to scroll together | |
| ``:vsplit`` | split vertically | Ctrl-w v |
| ``:windo`` | execute action on the visible buffers opened | |

## Quickfix and location list

 - https://freshman.tech/vim-quickfix-and-location-list/

## Substitutions

Use ``&&`` to repeat the last substitution.

  - http://vimregex.com/

## Scripting

 - https://devhints.io/vimscript

## Normal mode

 - ``g Ctrl-g``: give information about selected text
 - ``gi`` return in insert mode in the last place you exited it
 - ``gv`` reselect the last selection
 - ``g;`` go to older position in the changelist
 - ``g,`` go to newer position in the changelist
 - ``Ctrl-e``: move viewport one line up
 - ``Ctrl-y``: move viewport one line down

| Shortcut | Description |
|----------|-------------|
| ``Ctrl-u`` | move a page up |
| ``Ctrl-d`` | move a page down |
| ``zz`` | move the current line at the center |


### Window

| Shortcut | Description |
|----------|-------------|
| ``Ctrl-w + K`` | change vertical split to horizontal |
| ``Ctrl-w + H`` | change horizontal split to vertical |

## Insert mode

 - ``Ctrl-r %``: relative path of the current file
 - ``Ctrl-t``: indent current line
 - ``Ctrl-d``: backdent current line


## Cookbook

### Multiline editing

It's not immediate like other editors but it's possible, the best option is to
use a plugin like [vim-multiple-cursors](https://github.com/terryma/vim-multiple-cursors).

### Append text

This works out of the box in vim: with **Visual block mode** select the lines
you want to append text to, press ``$`` to move the cursor at the end of line
and then press ``A`` to start append mode. After you terminated to insert the
text, ``ESC`` and wait the text to update.

### Edit multiple files at once

 - [Effective editing of multiple files in Vim](https://jovica.org/posts/vim-edit-multiple-files/)

## Plugins

 - [ALE](https://github.com/dense-analysis/ale) Asynchronous Lint Engine is a plugin providing linting (syntax checking and semantic errors)

