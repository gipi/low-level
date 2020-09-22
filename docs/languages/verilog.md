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

### Sequential logic

There are two ways, **more clear**

```verilog
module accum(
    input clk,
    input data_i,
    input en_i,
    output [3:0] sum_o;
);

reg [WIDTH-1:0] sum_r, sum_next;

assign sum_o = sum_r;

always_comb
begin
    sum_next = sum_r;
    if (en_i)
        sum_next = sum_r + data_i;
end

always_ff @(posedge clk)
    sum_r <= sum_next;
```

and **shorter**

```verilog
module accum(
    input clk,
    input data_i,
    input en_i,
    output [3:0] sum_o;
);

reg [WIDTH-1:0] sum_r;

assign sum_o = sum_r;

always_ff @(posedge clk)
begin
  if (en_i)
    sum_r <= sum_r + data_i;
end 
```

## Links

 - [Verilog HDL Quick Reference Guide](https://sutherland-hdl.com/pdfs/verilog_2001_ref_guide.pdf)
 - Blocking vs. Nonblocking Assignments [slide](http://courses.csail.mit.edu/6.111/f2007/handouts/L06.pdf)
 - Understanding Verilog Blocking and Non-blocking Assignments [slides](https://sutherland-hdl.com/papers/1996-CUG-presentation_nonblocking_assigns.pdf)
