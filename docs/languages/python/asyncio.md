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


async def _runner():
    tasks = [whatever('a'), asyncio.sleep(1), whatever('b')]

    await asyncio.gather(*tasks)


print("-- w/o tasks")
start = time.time()

asyncio.run(main())

print("-- w tasks")
start = time.time()

asyncio.run(main2())

print(" -- w gather")
start = time.time()
asyncio.run(_runner())

```

```
-- w/o tasks
a: 0.0002 Hello!
a: 3.0034 Goodbye!
b: 4.0050 Hello!
b: 7.0085 Goodbye!
-- w tasks
a: 0.0002 Hello!
b: 0.0002 Hello!
a: 3.0026 Goodbye!
b: 3.0027 Goodbye!
 -- w gather
a: 0.0005 Hello!
b: 0.0006 Hello!
a: 3.0034 Goodbye!
b: 3.0035 Goodbye!
```

## Links

 - [Limiting concurrency in Python asyncio: the story of async imap_unordered()](https://death.andgravity.com/limit-concurrency)
