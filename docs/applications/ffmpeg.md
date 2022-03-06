# FFMPEG


## Dump M3U8 video

```
ffmpeg -i <m3u8 URL> -bsf:a aac_adtstoasc -vcodec copy -c copy -crf 50 $filename.mp4
```

