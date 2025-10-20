# Bring in static UIDs and GIDs for Weston and Wayland
USERADD_UID_TABLES:append = " files/torizon-static-weston-passwd "
USERADD_GID_TABLES:append = " files/torizon-static-weston-group "

# Allow the wayland DISTRO_FEATURE to be enabled
DISTRO_FEATURES_REMOVE:remove = "wayland"

# Ensure weston is built with the wayland PACKAGECONFIG
# Arguably this should be done in a weston bbappend but
# doing it here globally as part of the DISTRO settings
# works and will also be more future proof in case this
# variable is ever used anywhere else.
PACKAGECONFIG_IMX_REMOVALS:remove = "wayland"