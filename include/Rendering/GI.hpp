#include <Platform/Platform.hpp>
#include <Rendering/RenderTypes.hpp>
#define BUILD_PC (BUILD_PLAT == BUILD_WINDOWS || BUILD_PLAT == BUILD_POSIX)

#if BUILD_PC
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.hpp>
#elif BUILD_PLAT == BUILD_PSP
#include <gu2gl.h>
#elif BUILD_PLAT == BUILD_VITA
#include <vitaGL.h>
#endif

#define GI_ALPHA_TEST GL_ALPHA_TEST
#define GI_DEPTH_TEST GL_DEPTH_TEST
#define GI_SCISSOR_TEST GL_SCISSOR_TEST
#define GI_STENCIL_TEST GL_STENCIL_TEST
#define GI_BLEND GL_BLEND
#define GI_CULL_FACE GL_CULL_FACE
#define GI_DITHER GL_DITHER
#define GI_FOG GL_FOG
#define GI_CLIP_PLANES GL_CLIP_PLANES
#define GI_TEXTURE_2D GL_TEXTURE_2D
#define GI_LINE_SMOOTH GL_LINE_SMOOTH
#define GI_COLOR_TEST GL_COLOR_TEST
#define GI_COLOR_LOGIC_OP GL_COLOR_LOGIC_OP

/* Test Function */
#define GI_NEVER GL_NEVER
#define GI_ALWAYS GL_ALWAYS
#define GI_EQUAL GL_EQUAL
#define GI_NOTEQUAL GL_NOTEQUAL
#define GI_LESS GL_LESS
#define GI_LEQUAL GL_LEQUAL
#define GI_GREATER GL_GREATER
#define GI_GEQUAL GL_GEQUAL

/* Blending stuff */
#define GI_SRC_COLOR GL_SRC_COLOR
#define GI_ONE_MINUS_SRC_COLOR GL_ONE_MINUS_SRC_COLOR
#define GI_SRC_ALPHA GL_SRC_ALPHA
#define GI_ONE_MINUS_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
#define GI_DST_COLOR GL_DST_COLOR
#define GI_ONE_MINUS_DST_COLOR GL_ONE_MINUS_DST_COLOR
#define GI_DST_ALPHA GL_DST_ALPHA
#define GI_ONE_MINUS_DST_ALPHA GL_ONE_MINUS_DST_ALPHA
#define GI_FIX GL_FIX

/* Buffer Bits */
#define GI_COLOR_BUFFER_BIT GL_COLOR_BUFFER_BIT
#define GI_STENCIL_BUFFER_BIT GL_STENCIL_BUFFER_BIT
#define GI_DEPTH_BUFFER_BIT GL_DEPTH_BUFFER_BIT

/**
 * @brief Graphics Intermediate Layer -- this interacts directly with the
 * graphics API Recommended not to use this unless you know what you're doing
 *
 */
namespace GI {

using namespace Stardust_Celeste::Rendering;

auto init() -> void;
auto terminate() -> void;

auto enable(u32 state) -> void;
auto disable(u32 state) -> void;

auto set_culling_mode(bool enabled, bool ccw) -> void;

auto depth_func(u32 mode) -> void;
auto blend_func(u32 src, u32 dest) -> void;
auto alpha_func(u32 func, u32 value, u32 mask) -> void;

auto start_frame(bool dialog = false) -> void;
auto end_frame(bool vsync, bool dialog = false) -> void;

auto clear_color(Color color) -> void;
auto clear(u32 mask) -> void;

} // namespace GI