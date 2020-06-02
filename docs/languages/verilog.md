# Verilog

``verilog`` is an Hardware Description Language (``HDL``).

## Cookbook

### Initialize array

```verilog
parameter MEM_INIT_FILE = "";
reg [31:0] ram [255:0];
...
initial begin
  if (MEM_INIT_FILE != "") begin
    $readmemh(MEM_INIT_FILE, ram);
  end
end
```

## Links

 - [Verilog HDL Quick Reference Guide](https://sutherland-hdl.com/pdfs/verilog_2001_ref_guide.pdf)
 - Blocking vs. Nonblocking Assignments [slide](http://courses.csail.mit.edu/6.111/f2007/handouts/L06.pdf)
 - Understanding Verilog Blocking and Non-blocking Assignments [slides](https://sutherland-hdl.com/papers/1996-CUG-presentation_nonblocking_assigns.pdf)
