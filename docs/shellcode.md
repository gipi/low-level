Note that the usually the base pointer is trashed during the exploting
process in a normal exploitation process, but the stack pointer is not.


- http://www.blackhatlibrary.net/Shellcode/Null-free

Since the standard ``/bin/sh`` is a link to ``/bin/bash`` that
droppes privileges when called, you can call instead a script
like the following

```python
#!/usr/bin/env python2
import os
os.setresuid(os.geteuid(), os.geteuid(), os.geteuid())
os.execlp("bash", "bash")
```
