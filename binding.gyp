{
  "targets": [
    {
      "target_name": "warden",
      "cflags": ["-std=gnu++14", "-mavx2"],
      "sources": [
        "./src/native/warden.cc"
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}