# Git

## Edit commit

```
 -> add to the index some changes
$ git commit --amend
```

## Reset first commit

```
$ git update-ref -d HEAD
```

## Edit commit in an interactive rebase

```
$ git rebase --interactive <ref>^
 -> change the operation for the desired commit to "edit" and close the editor
 -> now you are in the desired commit
$ git reset HEAD^
 -> you can now commit the changes in as many commits as you want
$ git rebase --continue
```

## Set upstream for branch

```
(gp/falafel) $ git branch -u origin/kebab
Branch 'gp/falafel' set up to track remote branch 'kebab' from 'origin'.
```

## Diffing

A part from the normal ``git diff`` and the options predates from ``diff(1)``,
if you want colored output even in presence of a pipe, you must pass
``--color=always`` and use the ``-r`` option for ``less(1)``.

## Rebase one commit onto

This is particular: you want to rebase the tip of ``<branch>`` to ``<upstream>``,
probably is the same as ``cherry-pick``

```
$ git rebase <branch>^ <branch> --onto <upstream>
```

## Rebase preserving merges

```
$ git rebase --preserve-merges <upstream>
```

## Merge/rebase conflict resolution

When there are conflicts a few files are created

 - ``.BASE``: the revision in common
 - ``.REMOTE``: your code
 - ``.LOCAL``: the code whose you are adapting your
 - ``.ORIG``: the file containing the markers ``<<<<``, ``=====`` and ``>>>>``

It's possible to use ``git mergetool`` in order to help with resolution, in particular
with the flag ``--tool`` is possible to indicate which tool to use.

 - [Resolving conflicts during a Git rebase](https://codeinthehole.com/guides/resolving-conflicts-during-a-git-rebase/)

## Notes

```
$ git notes add <ref>
$ git notes edit <ref>
$ git notes append <ref>
$ git push origin ref/notes/commits
$ git fetch origin refs/notes/*:refs/notes/*
```

## Follow function code evolution

```
$ git log -L:<function name>:<path file>
```

## Search for functions

In some cases you need to look up in which function is present
some string of your choice: the following shows the matching occurrence
of the string plus a line with the function name containing it

```
$ git grep --show-function <some string>
```

otherwise is possible to search for a string obtaining all the code
of the function containing it

```
$ git grep -W <some string>
```

## Submodules

This is the most hated functionality by me: the interface is really hard to remember
and doesn't make sense.

### Status

```
$ git submodule status
-7ada843c5bb0bb49c7f2bf5db72f9969e4091ba2 hardware/victims/firmware/crypto/secAES-ATmega8515
 715baf70fb04100a2c9da9764161a0019c3a9e41 jupyter (remotes/origin/cw5dev-74-g715baf7)
-9bebfcbda448fb39e8cf99aa75db4e345d56572e openadc
-1f79b63d485587d6ec5243f78b0fa86eaea9931c tutorials
```
``-`` means the submodule needs to be initialized

### Update

```
$ git submodule update --init
Submodule 'hardware/victims/firmware/crypto/secAES-ATmega8515' (https://github.com/jmichelp/secAES-ATmega8515.git) registered for path 'hardware/victims/firmware/crypto/secAES-ATmega8515'
Submodule 'openadc' (git://git.assembla.com/openadc.git) registered for path 'openadc'
Submodule 'tutorials' (https://github.com/newaetech/chipwhisperer-tutorials.git) registered for path 'tutorials'
Cloning into '/opt/chipwhisperer-git/hardware/victims/firmware/crypto/secAES-ATmega8515'...
Cloning into '/opt/chipwhisperer-git/openadc'...
Cloning into '/opt/chipwhisperer-git/tutorials'...
Submodule path 'hardware/victims/firmware/crypto/secAES-ATmega8515': checked out '7ada843c5bb0bb49c7f2bf5db72f9969e4091ba2'
Submodule path 'openadc': checked out '9bebfcbda448fb39e8cf99aa75db4e345d56572e'
Submodule path 'tutorials': checked out '1f79b63d485587d6ec5243f78b0fa86eaea9931c'
```

90% of the case you need only to update&init together!

## Bundle

It's possible to use as transport for the repository the bundles

```
$ git bundle -h
usage: git bundle create [<options>] <file> <git-rev-list args>
   or: git bundle verify [<options>] <file>
   or: git bundle list-heads <file> [<refname>...]
   or: git bundle unbundle <file> [<refname>...]

    -v, --verbose         be verbose; must be placed before a subcommand
```

For example if you want to create a file bundle named ``kebab.bundle`` of your local repository with the
objects contained in the branch ``kebab``

```
$ git bundle create kebab.bundle kebab
```

the receiver needs only to fetch from it

```
$ git fetch kebab.bundle
```

## Links

 - [Git Submodules vs Git Subtrees](https://codewinsarguments.co/2016/05/01/git-submodules-vs-git-subtrees/)
 - [Ignoring mass reformatting commits with git blame](https://akrabat.com/ignoring-revisions-with-git-blame/)
 - [Git pre-push hook](https://riptutorial.com/git/example/27005/git-pre-push-hook)

