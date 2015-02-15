io.stdout:setvbuf("no")

MOAISim.openWindow( 'gwen', 800, 500 )
local layer = MOAILayer.new()
local viewport = MOAIViewport.new ()
viewport:setSize ( 800, 500 )
viewport:setScale ( 800, 500 )
layer:setViewport( viewport )
function bindMouseInput( sys )
	local x0, y0
	local function onMouseLeftEvent ( down )
		return sys:sendMouseButtonEvent( 0, down )
	end

	local function onMouseRightEvent ( down )
		return sys:sendMouseButtonEvent( 1, down )
	end

	local function onMouseMiddleEvent ( down )
		return sys:sendMouseButtonEvent( 2, down )
	end

	local function onMouseMoveEvent ( x, y )
		x, y = layer:wndToWorld( x, y )
		x, y = sys:worldToModel( x, y )
		y = - y
		local dx, dy
		if x0 then
			dx = x - x0
			dy = y - y0
		else
			dx, dy = 0,0
		end
		x0, y0 = x, y
		return sys:sendMouseMoveEvent( x, y, dx, dy )
	end

	MOAIInputMgr.device.mouseLeft:setCallback ( onMouseLeftEvent )
	MOAIInputMgr.device.mouseRight:setCallback ( onMouseRightEvent )
	MOAIInputMgr.device.pointer:setCallback ( onMouseMoveEvent )
end

MOAIRenderMgr.setBufferTable( { MOAIGfxDevice.getFrameBuffer() } )
MOAIGfxDevice.getFrameBuffer():setRenderTable( { layer } )

font = MOAIFont.new ()
font:load ( "OpenSans.ttf" )
font:setDefaultSize( 12 )
font:getCache():setColorFormat( MOAIImage.COLOR_FMT_RGBA_8888 )
font:getReader():setPenColor( 1,1,1,1 )
MOAIGwenMgr.registerFont( 'Arial',  font )

sys = MOAIGwenSystem.new()
sys:setLoc( -400, 250 )
-- skin = MOAIGwenSkinSimple.new()

skin = MOAIGwenSkinTexturedBase.new()
skin:init( 'DefaultSkin.png' )
skin:setDefaultFont( 'Arial', 9 )

sys:setSkin( skin )

sys:start()
bindMouseInput( sys )

layer:insertProp( sys )

canvas = sys:getCanvas()
canvas:setName( 'canvas-root' )

window = canvas:addChild( MOAIGwenWindowControl.new() )
window:setSize( 100, 100 )
window:setTitle( 'ABCDEFCG' )

groupbox = window:addChild( MOAIGwenGroupBox.new() )

checkbox = groupbox:addChild( MOAIGwenCheckBox.new() )

button = groupbox:addChild( MOAIGwenButton.new() )
button:setText( 'testme' )
button:setToolTip( 'Test ME now!')
button:setListener( MOAIGwenButton.EVENT_CLICK, function() 
	checkbox:toggle()
end)
button:setPos( 0, 50 )
groupbox:setSize( 100, 100 )

pickerWindow = canvas:addChild( MOAIGwenWindowControl.new() )
picker = pickerWindow:addChild( MOAIGwenColorPicker.new() )
picker:setListener( MOAIGwenColorPicker.EVENT_CHANGE, function()
	print('color changed:')
	print( picker:getColor() )
end  )
picker:setColor( 1, 1, 1, 1 )
pickerWindow:setSize( 300, 200 )
pickerWindow:setResizable( false )


local toolBar = canvas:addChild( MOAIGwenToolBar.new() )
local button1 = toolBar:addChild( MOAIGwenButton.new() )
toolBar:setSize( 200, 50 )
button1:setText( 'test me' )
-- label = window:addChild( MOAIGwenLabel.new() )
-- label:setText( 'This is a very huge story which we dont really want to talk at this momemnt!' )
-- label:setPos( 100, 100 )
-- label:setFont( 'Arial', 20 )
-- label:setSize( 1500, 150 )

-- button = window:addChild( MOAIGwenButton.new() )
-- button:setSize( 200, 30 )
-- -- button:setListener( MOAIGwenControl.EVENT_HOVER_ENTER, function() print'hover.enter' end )
-- -- button:setListener( MOAIGwenControl.EVENT_HOVER_EXIT, function() print'hover.exit' end )
-- button:setListener( MOAIGwenButton.EVENT_CLICK, function() 
-- 	local win = canvas:addChild( MOAIGwenWindowControl.new() )
-- 	win:setPos( math.random()*200, math.random()* 200 )
-- 	win:setListener( MOAIGwenWindowControl.EVENT_HOVER_ENTER, function( wnd )
-- 		print( 'enter window', wnd )
-- 	end )
-- 	win:setListener( MOAIGwenWindowControl.EVENT_CLOSE, function( wnd )
-- 		print( 'Window is closing', wnd )
-- 	end )
-- end )

