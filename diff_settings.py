def apply(config, args):
    config["baseimg"] = "baseroms/baserom.us.v2.z64"
    config["myimg"] = "build_pal_v2/dkr.us.v2.z64"
    config["mapfile"] = "build_pal_v2/dkr.us.v2.map"
    config["source_directories"] = ["src_pal_v2"]
    config["show_line_numbers_default"] = True
    config["expected_dir"] = "expected/"
