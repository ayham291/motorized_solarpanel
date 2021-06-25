# Motorized Solarpanel - PMT2

## The preferred way of cloning this repo

**use bare clone:**

```bash
$ git clone --bare https://github.com/ayham291/motorized_solarpanel motorized_solarpanel
$ cd motorized_solarpanel/
$ git worktree add master
$ cd master/
```

Now you have a bare repo with the worktree master

If you want to know more go to [devel](https://github.com/ayham291/motorized_solarpanel/tree/devel) branch

## The *app* directory - HOWTO

This directory is intended to be used with Platformio

```bash
$ cd /path/to/the/repo/motorized_solarpanel/devel/app && code .
```

_**IMPORTANT**_ change the settings in [platformio.ini](https://github.com/ayham291/motorized_solarpanel/blob/devel/app/platformio.ini#L16-18) to your own settings.

You could also leave it as is if your setup autorecognizes the ports

## The included webserver is only for testing purposes

<span style="color:red">NOT FOR PRODUCTION - VERY UNSAFE SETTINGS ARE ENABLED</span>.

## Project Participants

- Ayham Alhalaibi
- Andreas Schneider
- Johannes Schiessel
- Stefan Weig

## Author

[Ayham Alhalaibi](https://github.com/ayham291)
