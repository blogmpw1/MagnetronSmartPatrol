# Magnetron Smart Patrol — x86 build scaffold

**Status: build scaffold only; NOT a working gameplay mod.**

This project is deliberately safe: it builds a 32-bit Windows DLL, but it does not patch `gamemd.exe`, hook game functions, alter Magnetron behavior, or claim that the requested feature works. The gameplay hooks still need to be reverse-engineered and tested against the exact executable.

## Requested behavior to implement

- Only activate for a Magnetron executing a Shift+Z closed-loop patrol.
- Automatically acquire and lift eligible enemy vehicles during that patrol.
- If the carried vehicle's release/collision path meets an obstacle, release using the game's original release path and let the original collision/damage rules resolve the result.
- If no obstacle is on the relevant path, use normal release behavior.
- Resume the same patrol route after the automatic release.
- Never change manually ordered Magnetron behavior; manual player orders take priority immediately.

## Build on GitHub

1. Create a new empty GitHub repository.
2. Upload the contents of this ZIP (including the hidden `.github` folder).
3. Open **Actions** and run **Build x86 DLL** (or push a commit).
4. Download the `MagnetronSmartPatrol-build-scaffold` artifact.

The artifact is only a compile check / DLL scaffold. Do **not** install it expecting the gameplay feature to work.

## Executable identity note

The supplied `gamemd.exe` was measured as:

- Size: `4,813,072` bytes
- MD5: `fe2301a1f48841aa084aade100b25335`
- SHA-256: `7b8a068535d6af06845edf95ae829b113d00c02909330e16f197426cd7db94b6`
- PE: 32-bit x86, ImageBase `0x00400000`, entry RVA `0x003CD80F`

The MD5 does **not** match the commonly documented retail YR 1.001 MD5 (`937b14db32f07ee47e92a8114ebdbdde`) or The First Decade MD5 (`6604fd6f4ab71a11c708ea423dc0a29e`). Therefore the exact executable variant must be identified before hard-coded hooks are safe. Do not use guessed hook addresses.

## Next engineering milestone

Before implementing gameplay hooks, establish the exact executable build and verify these engine paths in that build:

1. Shift+Z patrol order creation and waypoint-loop state.
2. Magnetron locomotor target acquisition / attachment.
3. Original target release path invoked by Stop.
4. Carried-object collision and falling-damage resolution.
5. Patrol restoration without overriding a new manual order.

No hard-coded addresses are included until verified against the executable fingerprint.
