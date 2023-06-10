# Asyncio

```python
import asyncio
import time


async def whatever(name):
    print(f"{name}: {time.time() - start:.4f} Hello!")
    await asyncio.sleep(3.0)
    print(f"{name}: {time.time() - start:.4f} Goodbye!")


async def main():
    await whatever('a')
    await asyncio.sleep(1)
    await whatever('b')


async def main2():
    task_a = asyncio.create_task(whatever('a'))
    task_s = asyncio.create_task(asyncio.sleep(1))
    task_b = asyncio.create_task(whatever('b'))

    await task_a
    await task_s
    await task_b


print("-- w/o tasks")
start = time.time()

asyncio.run(main())

print("-- w tasks")
start = time.time()

asyncio.run(main2())
```

```
-- w/o tasks
a: 0.0002 Hello!
a: 3.0014 Goodbye!
b: 4.0031 Hello!
b: 7.0052 Goodbye!
-- w tasks
a: 0.0004 Hello!
b: 0.0005 Hello!
a: 3.0033 Goodbye!
b: 3.0034 Goodbye!
```
