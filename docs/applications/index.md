# Applications

## Gstreamer

 - [Home page](http://gstreamer.freedesktop.org/)
 - [QtMultimedia, FFMpeg, Gstreamer: comparing multimedia frameworks](https://www.ulduzsoft.com/2016/06/qtmultimedia-ffmpeg-gstreamer-comparing-multimedia-frameworks/)
 - http://www.einarsundgren.se/gstreamer-basic-real-time-streaming-tutorial/
 - [Original documetation from source code](http://cgit.freedesktop.org/gstreamer/gstreamer/tree/docs/design/part-overview.txt)
 - http://wiki.oz9aec.net/index.php/Gstreamer_cheat_sheet
 - http://www.cin.ufpe.br/~cinlug/wiki/index.php/Introducing_GStreamer
 - http://www.jonobacon.org/2006/12/27/using-gnonlin-with-gstreamer-and-python/
 - https://felipec.wordpress.com/2008/01/19/gstreamer-hello-world/
 - http://notes.brooks.nu/2011/01/gstreamer-video-crossfade-example/
 - http://www.oz9aec.net/index.php/gstreamer/366-gstinputselector-to-switch-between-different-cameras
 - [Picture compositing](http://www.oz9aec.net/index.php/gstreamer/347-more-gstreamer-tips-picture-in-picture-compositing)
 - https://github.com/fthiery/gst-gengui
 - https://github.com/guijemont/GstStabilizer
 - http://www.oz9aec.net/index.php/gstreamer/345-a-weekend-with-gstreamer
 - https://github.com/umlaeute/v4l2loopback/wiki/Gstreamer
 - http://cgit.freedesktop.org/gstreamer/gst-python/tree/examples/switch.py
 - [Queue after tee](http://gstreamer.freedesktop.org/wiki/FAQ#My_pipeline_with_multiple_sinks_never_reaches_the_PAUSED_state.2C_what_am_I_doing_wrong.3F)
 - [Some](http://8na.de/?p=91) tricks to get "easy" stuffs out of GStreamer.
 - [GNonlin example](https://bitbucket.org/andrecaldas/math-video-classes/src/293d21a9d60f/bin?at=default)
 - http://luisbg.blogalia.com/historias/61887
 - http://www.jonobacon.org/2006/08/28/getting-started-with-gstreamer-with-python/
 - http://pygstdocs.berlios.de/
 - http://gstreamer.freedesktop.org/data/doc/gstreamer/head/manual/html/section-dynamic-pipelines.html
 - http://wiki.pitivi.org/wiki/PyGST_Tutorial/Combining_Audio_and_Video
 - https://answers.opencv.org/question/202017/how-to-use-gstreamer-pipeline-in-opencv/
 - [gst-inference](https://github.com/RidgeRun/gst-inference) A GStreamer Deep Learning Inference Framework
 - [Creating Gstreamer Multimedia Pipeline With C++ Part 2](https://medium.com/analytics-vidhya/creating-gstreamer-multimedia-pipeline-with-c-part-2-d3085c471747)

First of all, a video came with two main types of data: audio and video. Since space is important, is important to compress data but since quality is important also, during the years has been developed a lot of codecs (this name came from their functions: *coder* and *encoder*). For a technical video overview look at the Xiph [videos](http://xiph.org/video/).

```
$ gst-launch -v -e  filesrc location="/home/gipi/Video/Nature by Numbers.mp4"  ! \
        qtdemux name=avi ! faad  ! pulsesink
```

And remember is not only about multimedia: http://www.cita.utoronto.ca/~kcannon/gstlalworkshop/intro_and_setup.html


### PIPELINES

Play with guessing

```
$ gst-launch -v playbin uri="file:///home/gipi/Video/Nature by Numbers.mp4"
```

Play an image

```
$ gst-launch-1.0 multifilesrc location=tmp_frames/frame_%02d.png caps="image/png, framerate=1/1" ! \
    pngdec ! \
    videoconvert ! \
    autovideosink
```

Autodetect streams and play it

```
$ gst-launch-1.0 -v --gst-debug=4 filesrc location=//streaming.mp4 ! \
        decodebin name=demux \
        demux. ! queue ! autovideosink \
        demux. ! queue ! autoaudiosink
```

Show your webcam

```
$ gst-launch-1.0 v4l2src  ! autovideosink
```

and now composite with a test pattern

```
$ gst-launch -e v4l2src ! \
        queue ! \
        ffmpegcolorspace ! \
        videoscale ! \
        video/x-raw-yuv, framerate=10/1, width=320, height=240 ! \
        videomixer name=mix ! \
        ffmpegcolorspace ! \
        xvimagesink \
        videotestsrc ! video/x-raw-yuv, framerate=10/1, width=640, height=360 ! mix.
```

Composite two videos, rescaling them to 900x600 pixels

```
$ gst-launch-1.0  -v  \
    filesrc location='0870_00_60.mkv' ! \
    decodebin ! \
    queue ! \
    videoscale ! video/x-raw,width=900,height=600 ! \
    queue ! videobox border-alpha=0 left=-900  ! videomixer name=mix ! \
    videoconvert ! timeoverlay ! autovideosink \
    filesrc location='0870_00_60.mkv' ! decodebin ! \
    queue ! \
    videoscale ! video/x-raw,width=900,height=600 ! \
    queue ! videobox border-alpha=0 left=0 ! mix.
```

Show an overlay over the video

```
$ gst-launch-1.0 videotestsrc ! timeoverlay font-desc=60px ! xvimagesink
```

Resize the output

```
$ gst-launch-1.0 -v filesrc location=assange-ecuador.mp4 ! decodebin ! \
        videoscale ! \
        video/x-raw,width=\(int\)320,height=\(int\)200 ! \
        autovideosink filter-caps=video/x-raw
```

Create a video stream from an image

```
$ gst-launch-1.0 filesrc location=image001.jpg ! jpegdec ! imagefreeze ! autovideosink
```

Remote resource via HTTP

```
$ gst-launch-1.0 souphttpsrc location=http://foo.com/miao.mp3 ! autoaudiosink
```

Attach to a mountpoint of icecast

```
$ gst-launch -v filesrc location=audio/04\ -\ Blu\ di\ metilene.ogg ! \
        decodebin ! \
        audioconvert ! \
        vorbisenc  !  \
        oggmux ! \
        shout2send ip=localhost port=8000 mount=/lov
```

Icecast, you know

```
$ gst-launch v4l2src ! \
        queue ! \
        ffmpegcolorspace ! \
        videoscale ! \
        video/x-raw-yuv,width=320,height=240 ! \
        tee name=tscreen ! \
        queue ! \
        autovideosink \
        tscreen. ! \
        queue ! \
        videorate ! \
        video/x-raw-yuv,framerate=25/2 ! \
        queue ! \
        theoraenc quality=16 ! \
        queue ! \
        oggmux name=mux \
        alsasrc ! \
        queue ! \
        audioconvert ! \
        vorbisenc quality=0.2 ! \
        queue ! \
        queue ! \
        mux. \
        mux. ! \
        queue ! \
        tee name=tfile ! \
        queue ! \
        filesink location=stream.ogg tfile. ! \
        queue ! \
        shout2send ip=192.168.0.5 port=8000 mount=test.ogv password=sourcepassword
```

From an IP camera that serves JPEG images (``multipartdemux`` is useless)

```
$ gst-launch souphttpsrc location=http://192.168.1.5:8080/videofeed ! \
    multipartdemux ! \
    jpegdec ! \
    xvimagesink
```

A simple test with audio

```
$ gst-launch -v audiotestsrc  wave=ticks ! audioconvert !  pulsesink
```

Send audio to a given pulse device

```
$ gst-launch -v filesrc location="yet-another-amazing-song.mp3" ! \
 decodebin ! \
 audioconvert ! \
 pulsesink device=nullsinkname
```

(the device can be a null sink created with `pactl load-module module-null-sink sink_name=nullsinkname`)

Screencast

```
$ gst-launch-1.0 ximagesrc ! \
    videoconvert ! \
    queue ! \
    vp8enc  ! mux. \
   pulsesrc ! audio/x-raw ! \
    queue ! \
    audioconvert ! \
    vorbisenc ! \
   mux. webmmux name=mux ! filesink location=screencast.webm
```

### Tee

```
gst-launch-1.0 \
 multifilesrc location=tmp_frames/frame_%02d.png caps="image/png, framerate=1/1" ! \
 pngdec ! \
 videoconvert ! \
 video/x-raw ! \
 queue ! tee name=t ! \
 queue ! videoconvert ! autovideosink \
 t. ! queue ! autovideosink
```

### Muxing

```
$ gst-launch-1.0 -v -e v4l2src ! \
  video/x-raw ! \
  videoconvert ! \
  vp8enc ! tee name=t ! \
  queue ! \
  matroskamux name=m ! filesink location=1.mkv  \
  pulsesrc ! vorbisenc ! \
  m.   \
  t. ! \
  queue ! webmmux ! filesink location=1.webm
```

### Build from source

Using ``scripts/create-uninstalled-setup.sh`` is possible to create a checkout of the sources
needed in ``~/gst``; in that directory a script ``gst-head`` is created: this is useful in order
to configure all the environment variables correctly and make the build success.

## Tmux

By default uses ``Ctrl-b`` as a control sequence

### Windows

| Key | Description |
|-----|-------------|
| ``c`` | create |
| ``w`` | list |
| ``n`` | next |
| ``p`` | previous |
| ``f`` | find |
| ``,`` | name |
| ``&`` | kill |
| ``l`` | last |

### Panes

| Key | Description |
|-----|-------------|
| ``%`` | vertical split |
| ``"`` | horizontal split |
| ``o`` | swap |
| ``q`` | show pane number |
| ``+`` | break pane into windows |
| ``-`` | restore pane from window |
| ``z`` | maximize |
| ``<space> `` | switch between layouts |
| ``{`` | move pan to the left |
| ``}`` | move pan to the right |
| ``t`` | big clock |

