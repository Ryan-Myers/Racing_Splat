def apply(config, args):
    config["baseimg"] = "baseroms/baserom.us.v1.z64"
    config["myimg"] = "build/dkr.us.v1.z64"
    config["mapfile"] = "build/dkr.us.v1.map"
    config["source_directories"] = ["src"]
    config["show_line_numbers_default"] = True
    config["expected_dir"] = "expected/"
