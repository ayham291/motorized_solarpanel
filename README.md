# Motorized Solarpanel - PMT2 - Development branch

## The preferred way of cloning this repo

**use bare clone:**

```
$ git clone --bare https://github.com/ayham291/motorized_solarpanel motorized_solarpanel
$ cd motorized_solarpanel/
$ git worktree add devel
$ cd devel/
```

Now you have a bare repo with the worktree devel

### Using a different worktree

if you want to work on a different worktree just execute:

`$ git worktree add <WORKTREE>`

**in the base folder** `$ cd /path/to/the/repo/motorized_solarpanel`

## The *app* directory - HOWTO

This directory is intended to be used with Platformio

`$ cd /path/to/the/repo/motorized_solarpanel/devel/app && code .`

_**IMPORTANT**_ change the settings in [platformio.ini](https://github.com/ayham291/motorized_solarpanel/blob/devel/app/platformio.ini#L16-18) to your own settings.

You could also leave it as is if your setup autorecognizes the ports

## Author

[Ayham Alhalaibi](https://github.com/ayham291)
